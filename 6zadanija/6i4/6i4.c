#include <stdio.h>
#include <stdlib.h>

int str_eq(const char *a,const char *b){
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i])return 0;
        i++;
    }
    return a[i]=='\0'&&b[i]=='\0';
}

int copy_file(const char *src,const char *dst){
    FILE *in=fopen(src,"rb");
    if(!in){
        printf("error: cannot open %s\n",src);
        return 1;
    }
    FILE *out=fopen(dst,"wb");
    if(!out){
        printf("error: cannot open %s\n",dst);
        fclose(in);
        return 1;
    }
    char buf[8192];
    size_t n;
    while((n=fread(buf,1,sizeof(buf),in))>0){
        if(fwrite(buf,1,n,out)!=n){
            printf("error: write to %s failed\n",dst);
            fclose(in);
            fclose(out);
            return 1;
        }
    }
    fclose(in);
    fclose(out);
    printf("copied %s -> %s\n",src,dst);
    return 0;
}

int merge_files(const char *outpath,int start,int argc,char *argv[]){
    FILE *out=fopen(outpath,"wb");
    if(!out){
        printf("error: cannot open %s\n",outpath);
        return 1;
    }
    char buf[8192];
    int merged=0;
    for(int i=start;i<argc;i++){
        FILE *in=fopen(argv[i],"rb");
        if(!in){
            printf("error: cannot open %s\n",argv[i]);
            continue;
        }
        size_t n;
        while((n=fread(buf,1,sizeof(buf),in))>0){
            if(fwrite(buf,1,n,out)!=n){
                printf("error: write to %s failed\n",outpath);
                fclose(in);
                fclose(out);
                return 1;
            }
        }
        fclose(in);
        merged++;
    }
    fclose(out);
    printf("merged %d file(s) -> %s\n",merged,outpath);
    return 0;
}

int split_file(const char *inpath,long chunk){
    if(chunk<=0){
        printf("error: invalid size\n");
        return 1;
    }
    FILE *in=fopen(inpath,"rb");
    if(!in){
        printf("error: cannot open %s\n",inpath);
        return 1;
    }
    char buf[8192];
    FILE *out=NULL;
    long written=0;
    int part=0;
    size_t n;
    while((n=fread(buf,1,sizeof(buf),in))>0){
        size_t idx=0;
        while(idx<n){
            if(out==NULL||written>=chunk){
                if(out)fclose(out);
                part++;
                char name[1024];
                snprintf(name,sizeof(name),"%s.part%d",inpath,part);
                out=fopen(name,"wb");
                if(!out){
                    printf("error: cannot create %s\n",name);
                    fclose(in);
                    return 1;
                }
                written=0;
            }
            long remain=chunk-written;
            size_t can=(size_t)(remain<(long)(n-idx)?remain:(long)(n-idx));
            if(fwrite(buf+idx,1,can,out)!=can){
                printf("error: write failed\n");
                fclose(in);
                fclose(out);
                return 1;
            }
            written+= (long)can;
            idx+=can;
        }
    }
    if(out)fclose(out);
    fclose(in);
    printf("split %s into %d part(s)\n",inpath,part);
    return 0;
}

int main(int argc,char *argv[]){
    if(argc<2){
        printf("Usage: %s <operation> <files...>\n",argv[0]);
        printf("  copy <src> <dst>\n");
        printf("  merge <output> <input1> <input2> ...\n");
        printf("  split <input> <size>\n");
        return 1;
    }

    char *op=argv[1];

    if(str_eq(op,"copy")){
        if(argc!=4){
            printf("Usage: %s copy <src> <dst>\n",argv[0]);
            return 1;
        }
        return copy_file(argv[2],argv[3]);
    }

    if(str_eq(op,"merge")){
        if(argc<4){
            printf("Usage: %s merge <output> <input1> <input2> ...\n",argv[0]);
            return 1;
        }
        return merge_files(argv[2],3,argc,argv);
    }

    if(str_eq(op,"split")){
        if(argc!=4){
            printf("Usage: %s split <input> <size>\n",argv[0]);
            return 1;
        }
        char *end=NULL;
        long chunk=strtol(argv[3],&end,10);
        if(*end!='\0'){
            printf("error: invalid size '%s'\n",argv[3]);
            return 1;
        }
        return split_file(argv[2],chunk);
    }

    printf("error: unknown operation '%s'\n",op);
    return 1;
}
#include <stdio.h>
#include <stdlib.h>



int is_flag(const char *s,char c){
    if(s==NULL)return 0;
    if(s[0]!='-')return 0;
    if(s[1]!=c)return 0;
    if(s[2]!='\0')return 0;
    return 1;
}

int main(int argc,char *argv[]){
    long n=0;
    int n_set=0;
    char *out=NULL;
    int verbose=0;

    char *items[256];
    int ic=0;

    if(argc==1){
        printf("usage: %s [-n num] [-o file] [-v] stuff...\n",argv[0]);
        return 0;
    }

    for(int i=1;i<argc;i++){
        char *a=argv[i];

        if(a[0]=='-'){
            if(is_flag(a,'n')){
                if(i+1>=argc){
                    printf("err: -n needs number\n");
                    return 1;
                }
                char *end=NULL;
                long v=strtol(argv[i+1],&end,10);
                if(*end!='\0'){
                    printf("err: bad number '%s'\n",argv[i+1]);
                    return 1;
                }
                n=v;
                n_set=1;
                i++;
                continue;
            }

            if(is_flag(a,'o')){
                if(i+1>=argc){
                    printf("err: -o needs filename\n");
                    return 1;
                }
                out=argv[i+1];
                i++;
                continue;
            }

            if(is_flag(a,'v')){
                verbose=1;
                printf("verbose on\n");
                continue;
            }

            printf("warn: unknown flag '%s'\n",a);
            continue;
        }

        if(ic<256){
            items[ic++]=a;
        }else{
            printf("warn: too many args, skip '%s'\n",a);
        }
    }

    if(n_set)printf("n=%ld\n",n);
    else printf("n=not set\n");

    if(out)printf("out=%s\n",out);
    else printf("out=not set\n");

    if(ic==0){
        printf("no items\n");
    }else{
        printf("items(%d):\n",ic);
        for(int k=0;k<ic;k++){
            if(verbose)printf("do: %s\n",items[k]);
            printf("%s\n",items[k]);
        }
    }

    return 0;
}







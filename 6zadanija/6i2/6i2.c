#include <stdio.h>

int is_space(char c){

    if(c==' ')return 1;
    if(c=='\n')return 1;

    if(c=='\t')return 1;
    if(c=='\r')return 1;
    if(c=='\v')return 1;
    if(c=='\f')return 1;

    return 0;

}

int main(int argc,char *argv[]){

    if(argc<2){
        printf("%s <files...>\n",argv[0]);
        return 1;
    }


    for(int i=1;i<argc;i++){

        FILE *f=fopen(argv[i],"rb");

        if(!f){
            printf("error: cannot open %s\n",argv[i]);

            if(i<argc-1)printf("\n");
            continue;
        }

        long bytes=0;
        long lines=0;
        long words=0;
        int inword=0;
        int ch;

        while((ch=fgetc(f))!=EOF){
            bytes++;

            if(ch=='\n'){
                lines++;
            }

            if(is_space((char)ch)){
                if(inword){
                    inword=0;
                }
            }else{
                if(!inword){
                    words++;
                    inword=1;
                }
            }
        }

        fclose(f);

        printf("Filename: %s\n",argv[i]);

        printf("Size in bytes: %ld\n",bytes);

        printf("Number of lines: %ld\n",lines);

        printf("Number of words: %ld\n",words);

        if(i<argc-1){

            printf("\n");
        }
    }


    return 0;

}



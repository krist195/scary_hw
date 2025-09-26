#include <stdio.h>

int main(int argc,char *argv[]){
    
    if(argc<2){


        printf("%s <file1> <file2> ...\n",argv[0]);
        return 1;
    }


    for(int i=1;i<argc;i++){
        FILE *f=fopen(argv[i],"rb");

        if(!f){
            printf("error: cannot open %s\n",argv[i]);

            if(i<argc-1)printf("\n");
            continue;
        }

        printf("Filename: %s\n",argv[i]);

        int ch,last=-1;

        while((ch=fgetc(f))!=EOF){
            putchar(ch);
            last=ch;
        }

        if(last!='\n')putchar('\n');

        fclose(f);

        if(i<argc-1)printf("\n");
    }


    return 0;
}


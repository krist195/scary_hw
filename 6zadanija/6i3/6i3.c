#include <stdio.h>

int str_eq(const char *a,const char *b){
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i])return 0;
        i++;
    }
    return a[i]=='\0'&&b[i]=='\0';
}

char lowerc(char c){
    if(c>='A'&&c<='Z')return (char)(c+('a'-'A'));
    return c;
}

int contains(const char *text,const char *word,int icase){
    if(word[0]=='\0')return 0;
    for(int i=0;text[i]!='\0';i++){
        int j=0;
        while(word[j]!='\0'&&text[i+j]!='\0'){
            char a=text[i+j];
            char b=word[j];
            if(icase){
                a=lowerc(a);
                b=lowerc(b);
            }
            if(a!=b)break;
            j++;
        }
        if(word[j]=='\0')return 1;
    }
    return 0;
}

int main(int argc,char *argv[]){
    if(argc<3){
        printf("Usage: %s [-i] <word> <files...>\n",argv[0]);
        return 1;
    }

    int icase=0;
    int widx=1;
    int fstart=2;

    if(str_eq(argv[1],"-i")){
        icase=1;
        if(argc<4){
            printf("Usage: %s [-i] <word> <files...>\n",argv[0]);
            return 1;
        }
        widx=2;
        fstart=3;
    }

    char *word=argv[widx];

    char buf[4096];

    for(int i=fstart;i<argc;i++){
        FILE *f=fopen(argv[i],"rb");

        if(!f){
            printf("error: cannot open %s\n",argv[i]);

            continue;
        }

        long line=0;

        while(fgets(buf,sizeof(buf),f)){
            line++;

            if(contains(buf,word,icase)){
                int need_nl=1;
                int k=0;
                while(buf[k]!='\0'){
                    if(buf[k]=='\n')need_nl=0;
                    k++;
                }
                printf("%s:%ld:%s",argv[i],line,buf);
                if(need_nl)printf("\n");
            }
        }

        fclose(f);
    }

    return 0;
}
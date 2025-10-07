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

int main(int argc,char *argv[]){
    long port=8080;
    char *host="localhost";
    int debug=0;

    for(int i=1;i<argc;i++){
        char *arg=argv[i];

        if(str_eq(arg,"--port")||str_eq(arg,"-p")){
            if(i+1>=argc){
                printf("err: port needs number\n");
                return 1;
            }
            char *end=NULL;
            long v=strtol(argv[i+1],&end,10);
            if(*end!='\0'){
                printf("err: bad port '%s'\n",argv[i+1]);
                return 1;
            }
            port=v;
            i++;
            continue;
        }

        if(str_eq(arg,"--host")||str_eq(arg,"-h")){
            if(i+1>=argc){
                printf("err: host needs value\n");
                return 1;
            }
            host=argv[i+1];
            i++;
            continue;
        }

        if(str_eq(arg,"--debug")||str_eq(arg,"-d")){
            debug=1;
            continue;
        }

        if(arg[0]=='-'){
            printf("warn: unknown flag '%s'\n",arg);
            continue;
        }
    }

    printf("host=%s\n",host);
    printf("port=%ld\n",port);
    printf("debug=%s\n",debug?"on":"off");
    return 0;
}
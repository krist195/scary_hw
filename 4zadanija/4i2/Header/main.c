#include <stdio.h>
#include "str_utils.h"
#include "printers.h"
#include "cli.h"

int main(int argc,char *argv[]){
    if(argc<3){
        print_usage(argv[0]);
        return 1;
    }

    char *op=argv[1];

    if(str_eq(op,"upper")){
        int i=2;
        while(i<argc){
            print_upper(argv[i]);
            if(i<argc-1)putchar(' ');
            i++;
        }
        putchar('\n');
    }else if(str_eq(op,"lower")){
        int i=2;
        while(i<argc){
            print_lower(argv[i]);
            if(i<argc-1)putchar(' ');
            i++;
        }
        putchar('\n');
    }else if(str_eq(op,"reverse")){
        int i=2;
        while(i<argc){
            print_reverse(argv[i]);
            if(i<argc-1)putchar(' ');
            i++;
        }
        putchar('\n');
    }else if(str_eq(op,"concat")){
        int i=2;
        while(i<argc){
            print_raw(argv[i]);
            i++;
        }
        putchar('\n');
    }else{
        print_unknown(op);
        return 1;
    }

    return 0;
}
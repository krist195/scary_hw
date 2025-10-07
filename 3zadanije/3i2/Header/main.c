#include <stdio.h>
#include "parse.h"
#include "math_ops.h"
#include "print_ops.h"

int main(int argc,char *argv[]){
    if(argc<2){
        print_usage(argv[0]);
        return 1;
    }

    if(((argc-1)%2)==0){
        printf("pattern must be <number> <operator> <number> ...\n");
        return 1;
    }

    long result=0;
    long v=0;

    if(!parse_num(argv[1],&v)){
        print_invalid_number(argv[1]);
        return 1;
    }
    result=v;

    for(int i=2;i<argc;i+=2){
        char *tok=argv[i];
        char op=read_op(tok);

        if(op=='\0'){
            print_op_not_single(tok);
            return 1;
        }

        if(!is_op(op)){
            print_invalid_operator(op);
            return 1;
        }

        if(!parse_num(argv[i+1],&v)){
            print_invalid_number(argv[i+1]);
            return 1;
        }

        int st=apply(&result,op,v);
        if(st==2){
            print_division_by_zero();
            return 1;
        }else if(st!=0){
            print_invalid_operator(op);
            return 1;
        }
    }

    print_result(result);
    return 0;
}
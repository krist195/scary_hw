#include <stdlib.h>
#include "calc.h"
#include "print_ops.h"

int main(int argc,char *argv[]){
    if(argc!=4){
        print_usage(argv[0]);
        return 1;
    }

    int a=atoi(argv[1]);
    int b=atoi(argv[3]);
    char op=argv[2][0];

    int result=0;
    int status=eval(a,op,b,&result);

    if(status==0){
        print_result(result);
        return 0;
    }else{
        print_unknown_operator(op);
        return 1;
    }
}
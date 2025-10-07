#include "math_ops.h"

int is_op(char op){
    return op=='+'||op=='-'||op=='*'||op=='/';
}

int apply(long *acc,char op,long rhs){
    if(op=='+'){*acc+=rhs;return 0;}
    if(op=='-'){*acc-=rhs;return 0;}
    if(op=='*'){*acc*=rhs;return 0;}
    if(op=='/'){
        if(rhs==0)return 2;
        *acc/=rhs;
        return 0;
    }
    return 1;
}
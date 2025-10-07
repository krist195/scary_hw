#include "calc.h"

int eval(int a,char op,int b,int *out){
    switch(op){
        case '+': *out=a+b; return 0;
        case '-': *out=a-b; return 0;
        case '*': *out=a*b; return 0;
        case '/': return 1;      /* как в твоём коде: деление не реализовано */
        default:  return 1;
    }
}
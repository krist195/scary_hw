#include <stdio.h>
#include "print_ops.h"

void print_usage(const char *prog){
    printf("%s <word> <text1> <text2> ...\n",prog);
}

void print_match(int arg_index,const char *text){
    printf("arg %d: %s\n",arg_index,text);
}

void print_no_matches(void){
    printf("no matches\n");
}
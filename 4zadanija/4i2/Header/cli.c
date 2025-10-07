#include <stdio.h>
#include "cli.h"

void print_usage(const char *prog){
    printf("%s <upper|lower|reverse|concat> <strings...>\n",prog);
}

void print_unknown(const char *op){
    printf("unknown operation '%s'\n",op);
}
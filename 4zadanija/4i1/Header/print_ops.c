#include <stdio.h>
#include "print_ops.h"

void print_usage(const char *prog){
    printf("%s <strings...>\n",prog);
}

void print_item(const char *s,size_t len){
    printf("%s: %zu\n",s,len);
}

void print_total(size_t total){
    printf("Total: %zu\n",total);
}
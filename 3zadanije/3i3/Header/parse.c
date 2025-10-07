#include <stdlib.h>
#include "parse.h"

int parse_num(const char *s,long *out){
    char *end=NULL;
    long v=strtol(s,&end,10);
    if(*end!='\0')return 0;
    *out=v;
    return 1;
}
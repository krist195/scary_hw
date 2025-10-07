#include <stdio.h>
#include "printers.h"
#include "str_utils.h"

void print_upper(const char *s){
    int i=0;
    while(s[i]!='\0'){
        char up=to_upper_char(s[i]);
        putchar(up);
        i++;
    }
}

void print_lower(const char *s){
    int i=0;
    while(s[i]!='\0'){
        char lo=to_lower_char(s[i]);
        putchar(lo);
        i++;
    }
}

void print_reverse(const char *s){
    int n=str_len(s);
    int j=n-1;
    while(j>=0){
        putchar(s[j]);
        j--;
    }
}

void print_raw(const char *s){
    int i=0;
    while(s[i]!='\0'){
        putchar(s[i]);
        i++;
    }
}
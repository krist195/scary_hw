#include "str_utils.h"

int str_len(const char *s){
    int n=0;
    while(s[n]!='\0'){
        n++;
    }
    return n;
}

int str_eq(const char *a,const char *b){
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i])return 0;
        i++;
    }
    if(a[i]=='\0'&&b[i]=='\0')return 1;
    else return 0;
}

char to_upper_char(char c){
    if(c>='a'&&c<='z'){
        char diff='a'-'A';
        char upper=(char)(c-diff);
        return upper;
    }else{
        return c;
    }
}

char to_lower_char(char c){
    if(c>='A'&&c<='Z'){
        char diff='a'-'A';
        char lower=(char)(c+diff);
        return lower;
    }else{
        return c;
    }
}
#include "find.h"
#include "str_case.h"

int contains_icase(const char *text,const char *word){
    if(word[0]=='\0')return 0;
    for(int i=0;text[i]!='\0';i++){
        int j=0;
        while(word[j]!='\0'&&text[i+j]!='\0'){
            char a=lowerc(text[i+j]);
            char b=lowerc(word[j]);
            if(a!=b)break;
            j++;
        }
        if(word[j]=='\0')return 1;
    }
    return 0;
}
#include "str_case.h"

char lowerc(char c){
    if(c>='A'&&c<='Z')return (char)(c+('a'-'A'));
    return c;
}
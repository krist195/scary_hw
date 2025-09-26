#include <stdio.h>




int str_len(const char *s){

    int n = 0;
    while (s[n] != '\0'){
        n++;
    }
    return n;
}


int str_eq(const char *a, const char *b){

    int i = 0;
    while (a[i] != '\0' && b[i] != '\0'){
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0'){
        return 1;
    } else {
        return 0;
    }

}





char to_upper_char(char c){

    if (c >= 'a' && c <= 'z'){
        char diff = 'a' - 'A';
        char upper = (char)(c - diff);
        return upper;
    } else {
        return c;
    }
}

char to_lower_char(char c){

    if (c >= 'A' && c <= 'Z'){
        char diff = 'a' - 'A';
        char lower = (char)(c + diff);
        return lower;
    } else {

        return c;
    }
}




void print_upper(const char *s){

    int i = 0;
    while (s[i] != '\0'){
        char up = to_upper_char(s[i]);
        putchar(up);
        i++;
    }
}

void print_lower(const char *s){

    int i = 0;
    while (s[i] != '\0'){

        char lo = to_lower_char(s[i]);
        putchar(lo);
        i++;
    }
}

void print_reverse(const char *s){

    int n = str_len(s);
    int j = n - 1;

    while (j >= 0) {
        putchar(s[j]);
        j--;
    }
}

void print_raw(const char *s){
    int i = 0;
    while (s[i] != '\0'){
        putchar(s[i]);
        i++;
    }
}





int main(int argc, char *argv[]){
    if (argc < 3){
        printf("%s <upper|lower|reverse|concat> <strings...>\n", argv[0]);

        return 1;

    }

    char *op = argv[1];

    if (str_eq(op, "upper")){

        int i = 2;
        while (i < argc) {
            print_upper(argv[i]);
            if (i < argc - 1){
                putchar(' ');
            }
            i++;
        }
        putchar('\n');



    } else if (str_eq(op, "lower")){
        int i = 2;
        while (i < argc) {
            print_lower(argv[i]);
            if (i < argc - 1){
                putchar(' ');
            }
            i++;
        }


        putchar('\n');


    } else if (str_eq(op, "reverse")){
        int i = 2;
        while (i < argc){
            print_reverse(argv[i]);
            if (i < argc - 1){
                putchar(' ');
            }
            i++;
        }
        putchar('\n');

    } else if (str_eq(op, "concat")){

        int i = 2;

        while (i < argc){
            print_raw(argv[i]);
            i++;
        }
        putchar('\n');
    } else{
        printf("unknown operation '%s'\n", op);
        return 1;
    }



    return 0;
}




#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
    if (argc != 4){
        printf("Use ./calc <num1> <operator> <num2>\n");
        return 1;
    }




    int a = atoi(argv[1]);

    int b = atoi(argv[3]);
    char op = argv[2][0];

    int result;


    
    switch (op){
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':

        default:
            printf("Unknown operator: %c\n", op);
            return 1;
    }




    printf("Result: %d\n", result);
    return 0;
}



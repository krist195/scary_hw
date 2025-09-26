#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){




    if (argc < 2){
        printf(" %s <number> <operator> <number> ...\n", argv[0]);
        return 1;
    }

    if (((argc - 1) % 2) == 0){
        printf("pattern must be <number> <operator> <number> ...\n");
        return 1;
    }

    char *end = NULL;
    long result = strtol(argv[1], &end, 10);
    if (*end != '\0'){
        printf("invalid number '%s'\n", argv[1]);
        return 1;
    }

    for (int i = 2; i < argc; i += 2){
        char *tok = argv[i];
        char op = tok[0];

        if (tok[1] != '\0'){
            printf("operator must be a single character, got '%s'\n", tok);
            return 1;
        }



        

        if (op != '+' && op != '-' && op != '*' && op != '/'){
            printf("invalid operator '%c' (use +-*/)\n", op);
            return 1;
        }

        end = NULL;
        long rhs = strtol(argv[i + 1], &end, 10);
        if (*end != '\0'){
            printf("invalid number '%s'\n", argv[i + 1]);
            return 1;
        }

        if (op == '+'){
            result = result + rhs;
        } else if (op == '-'){
            result = result - rhs;
        } else if (op == '*'){
            result = result * rhs;
        } else if (op == '/'){
            if (rhs == 0) {
                printf("division by zero\n");
                return 1;
            }
            result = result / rhs;
        }
    }



    printf("Res: %ld\n", result);
    return 0;
}




#include <stdlib.h>            // strtol
#include "math_operations.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    if (((argc - 1) % 2) == 0) {
        print_pattern_error();
        return 1;
    }

    char *end = 0;
    long result = strtol(argv[1], &end, 10);
    if (*end != '\0') {
        print_invalid_number(argv[1]);
        return 1;
    }

    for (int i = 2; i < argc; i += 2) {
        char *tok = argv[i];
        char op = tok[0];

        if (tok[1] != '\0') {
            print_operator_not_single(tok);
            return 1;
        }

        if (!is_supported_operator(op)) {
            print_invalid_operator_char(op);
            return 1;
        }

        end = 0;
        long rhs = strtol(argv[i + 1], &end, 10);
        if (*end != '\0') {
            print_invalid_number(argv[i + 1]);
            return 1;
        }

        if (op == '+') {
            result = addl(result, rhs);
        } else if (op == '-') {
            result = subl(result, rhs);
        } else if (op == '*') {
            result = mull(result, rhs);
        } else { // '/'
            if (rhs == 0) {
                print_division_by_zero();
                return 1;
            }
            result = divl(result, rhs);
        }
    }

    print_result(result);
    return 0;
}
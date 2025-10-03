#include "calc.h"
#include "parse.h"
#include "math_operations.h"
#include "print_operations.h"

int eval_args(int argc, char *argv[], long *out_result) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }
    if (((argc - 1) % 2) == 0) {
        print_pattern_error();
        return 1;
    }

    int ok = 0;
    long result = parse_long(argv[1], &ok);
    if (!ok) {
        print_invalid_number(argv[1]);
        return 1;
    }

    for (int i = 2; i < argc; i += 2) {
        char op = 0;
        if (!is_single_char_operator(argv[i], &op)) {
            print_operator_not_single(argv[i]);
            return 1;
        }
        if (!is_supported_operator(op)) {
            print_invalid_operator_char(op);
            return 1;
        }

        long rhs = parse_long(argv[i + 1], &ok);
        if (!ok) {
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

    *out_result = result;
    return 0;
}
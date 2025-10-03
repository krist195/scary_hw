#include <stdio.h>
#include "string_utils.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("%s <upper|lower|reverse|concat> <strings...>\n", argv[0]);
        return 1;
    }

    char *op = argv[1];

    if (str_eq(op, "upper")) {
        for (int i = 2; i < argc; i++) {
            print_upper(argv[i]);
            if (i < argc - 1) putchar(' ');
        }
        putchar('\n');

    } else if (str_eq(op, "lower")) {
        for (int i = 2; i < argc; i++) {
            print_lower(argv[i]);
            if (i < argc - 1) putchar(' ');
        }
        putchar('\n');

    } else if (str_eq(op, "reverse")) {
        for (int i = 2; i < argc; i++) {
            print_reverse(argv[i]);
            if (i < argc - 1) putchar(' ');
        }
        putchar('\n');

    } else if (str_eq(op, "concat")) {
        for (int i = 2; i < argc; i++) {
            print_raw(argv[i]);
        }
        putchar('\n');

    } else {
        printf("unknown operation '%s'\n", op);
        return 1;
    }

    return 0;
}
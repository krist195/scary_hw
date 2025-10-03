#include <stdlib.h>          // atoi
#include "calc.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    int a = atoi(argv[1]);
    char op = argv[2][0];
    int b = atoi(argv[3]);

    int result = 0;
    int status = eval(a, op, b, &result);

    if (status == 0) {
        print_result(result);
        return 0;
    } else if (status == 2) {
        print_division_by_zero();
        return 1;
    } else {
        print_unknown_operator(op);
        return 1;
    }
}
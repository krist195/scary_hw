#include <stdio.h>
#include "print_operations.h"

void print_result(int result) {
    printf("Result: %d\n", result);
}

void print_usage(void) {
    printf("Use ./calc <num1> <operator> <num2>\n");
}

void print_unknown_operator(char op) {
    printf("Unknown operator: %c\n", op);
}

void print_division_by_zero(void) {
    printf("Error: division by zero\n");
}
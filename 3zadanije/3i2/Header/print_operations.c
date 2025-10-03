#include <stdio.h>
#include "print_operations.h"

void print_result(long result) {
    printf("Res: %ld\n", result);
}

void print_usage(const char *progname) {
    printf(" %s <number> <operator> <number> ...\n", progname);
}

void print_pattern_error(void) {
    printf("pattern must be <number> <operator> <number> ...\n");
}

void print_invalid_number(const char *s) {
    printf("invalid number '%s'\n", s);
}

void print_operator_not_single(const char *tok) {
    printf("operator must be a single character, got '%s'\n", tok);
}

void print_invalid_operator_char(char op) {
    printf("invalid operator '%c' (use +-*/)\n", op);
}

void print_division_by_zero(void) {
    printf("division by zero\n");
}
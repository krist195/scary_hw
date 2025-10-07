#include <stdio.h>
#include "print_ops.h"

void print_usage(const char *prog){ printf("Use %s <num1> <operator> <num2>\n",prog); }
void print_result(int r){ printf("Result: %d\n",r); }
void print_unknown_operator(char op){ printf("Unknown operator: %c\n",op); }
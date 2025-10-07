#include <stdio.h>
#include "print_ops.h"

void print_usage(const char *prog){ printf(" %s <number> <operator> <number> ...\n",prog); }
void print_invalid_number(const char *s){ printf("invalid number '%s'\n",s); }
void print_op_not_single(const char *tok){ printf("operator must be a single character, got '%s'\n",tok); }
void print_invalid_operator(char op){ printf("invalid operator '%c' (use +-*/)\n",op); }
void print_division_by_zero(void){ printf("division by zero\n"); }
void print_result(long r){ printf("Res: %ld\n",r); }
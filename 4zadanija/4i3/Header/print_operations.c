#include <stdio.h>
#include "print_operations.h"

void print_usage(const char *progname) {
    printf("%s <word> <text1> <text2> ...\n", progname);
}

void print_match(int arg_index, const char *text) {
    printf("arg %d: %s\n", arg_index, text);
}

void print_no_matches(void) {
    printf("no matches\n");
}
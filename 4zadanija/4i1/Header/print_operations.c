#include <stdio.h>
#include "print_operations.h"

void print_usage(const char *progname) {
    printf("%s <strings...>\n", progname);
}

void print_item_len(const char *s, size_t len) {
    printf("%s: %zu\n", s, len);
}

void print_total(size_t total) {
    printf("Total: %zu\n", total);
}
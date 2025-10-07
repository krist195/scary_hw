#include <stdio.h>
#include "print_operations.h"

void print_help(const char *prog) {
    printf("Usage: %s [ -v | --verbose ] [ -h | --help ] <args...>\n", prog);
    printf("  -v, --verbose   enable verbose output\n");
    printf("  -h, --help      show this help message\n");
}

void print_verbose_enabled(void) {
    printf("[VERBOSE] Verbose mode enabled\n");
}

void print_verbose_processing(const char *arg) {
    printf("[VERBOSE] Processing argument: %s\n", arg);
}

void print_verbose_done(int count) {
    printf("[VERBOSE] Done. Processed %d item(s)\n", count);
}

void print_warning_unknown_flag(const char *flag) {
    printf("Warning: unknown flag '%s' (ignored)\n", flag);
}

void print_plain(const char *s) {
    printf("%s\n", s);
}
#include <stdio.h>
#include "print_operations.h"

void print_usage(const char *progname) {
    printf("Usage: %s <numbers...>\n", progname);
}

void print_warning_invalid(const char *s) {
    printf("Warning: invalid number '%s' — skipped\n", s);
}

void print_no_valid_numbers(void) {
    printf("No valid numbers.\n");
}

void print_count(int count) { printf("Count: %d\n", count); }
void print_sum(long sum)    { printf("Sum: %ld\n", sum); }
void print_avg(double avg)  { printf("Average: %.2f\n", avg); }
void print_min(long min)    { printf("Min: %ld\n", min); }
void print_max(long max)    { printf("Max: %ld\n", max); }
#include <stdio.h>
#include "print_ops.h"

void print_usage(const char *prog){ printf("Usage: %s <numbers...>\n",prog); }
void print_warn_invalid(const char *s){ printf("Warning: invalid number '%s' — skipped\n",s); }
void print_no_valid(void){ printf("No valid numbers.\n"); }
void print_stats(int count,long sum,double avg,long min,long max){
    printf("Count: %d\n",count);
    printf("Sum: %ld\n",sum);
    printf("Average: %.2f\n",avg);
    printf("Min: %ld\n",min);
    printf("Max: %ld\n",max);
}
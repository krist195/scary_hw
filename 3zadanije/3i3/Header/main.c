#include <stdlib.h>            // strtol
#include "stats.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    struct Stats s;
    stats_init(&s);

    for (int i = 1; i < argc; i++) {
        char *end = 0;
        long val = strtol(argv[i], &end, 10);

        if (*end != '\0') {
            print_warning_invalid(argv[i]);
            continue;
        }

        stats_add(&s, val);
    }

    if (s.count == 0) {
        print_no_valid_numbers();
        return 1;
    }

    double avg = stats_avg(&s);

    print_count(s.count);
    print_sum(s.sum);
    print_avg(avg);
    print_min(s.min);
    print_max(s.max);

    return 0;
}
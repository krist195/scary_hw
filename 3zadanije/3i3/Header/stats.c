#include "stats.h"

void stats_init(struct Stats *s) {
    s->sum = 0;
    s->min = 0;
    s->max = 0;
    s->count = 0;
}

void stats_add(struct Stats *s, long val) {
    if (s->count == 0) {
        s->min = val;
        s->max = val;
    } else {
        if (val < s->min) s->min = val;
        if (val > s->max) s->max = val;
    }
    s->sum += val;
    s->count++;
}

double stats_avg(const struct Stats *s) {
    if (s->count == 0) return 0.0;
    return (double)s->sum / (double)s->count;
}
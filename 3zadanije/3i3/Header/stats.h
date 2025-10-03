struct Stats {
    long sum;
    long min;
    long max;
    int  count;
};

void stats_init(struct Stats *s);
void stats_add(struct Stats *s, long val);
double stats_avg(const struct Stats *s);
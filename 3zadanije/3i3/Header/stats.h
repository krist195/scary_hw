typedef struct{
    long sum;
    long min;
    long max;
    int count;
}Stats;

void stats_init(Stats *s);
void stats_add(Stats *s,long v);
double stats_avg(Stats *s);
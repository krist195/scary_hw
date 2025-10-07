#include "stats.h"

void stats_init(Stats *s){
    s->sum=0;
    s->min=0;
    s->max=0;
    s->count=0;
}

void stats_add(Stats *s,long v){
    if(s->count==0){
        s->min=v;
        s->max=v;
    }else{
        if(v<s->min)s->min=v;
        if(v>s->max)s->max=v;
    }
    s->sum+=v;
    s->count++;
}

double stats_avg(Stats *s){
    if(s->count==0)return 0.0;
    return (double)s->sum/(double)s->count;
}
#include "parse.h"
#include "stats.h"
#include "print_ops.h"

int main(int argc,char *argv[]){
    if(argc<2){
        print_usage(argv[0]);
        return 1;
    }

    Stats st;
    stats_init(&st);

    for(int i=1;i<argc;i++){
        long v=0;
        if(!parse_num(argv[i],&v)){
            print_warn_invalid(argv[i]);
            continue;
        }
        stats_add(&st,v);
    }

    if(st.count==0){
        print_no_valid();
        return 1;
    }

    double avg=stats_avg(&st);
    print_stats(st.count,st.sum,avg,st.min,st.max);
    return 0;
}
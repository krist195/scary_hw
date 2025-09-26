#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    
    if (argc < 2)
    {
        printf("Usage: %s <numbers...>\n", argv[0]);

        return 1;
    }

    long sum = 0;
    long min = 0;
    long max = 0;
    int count = 0;

    for (int i = 1; i < argc; i++){

        char *end = NULL;

        long val = strtol(argv[i], &end, 10);



        if (*end != '\0'){
            printf("Warning: invalid number '%s' — skipped\n", argv[i]);
            continue;
        }

        if (count == 0){
            min = max = val;
        } else{
            if (val < min) min = val;
            if (val > max) max = val;
        }

        sum += val;
        count++;
    }

    if (count == 0)  {
        printf("No valid numbers.\n");
        return 1;
    }


    double avg = (double)sum / (double)count;

    printf("Count: %d\n", count);
    printf("Sum: %ld\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Min: %ld\n", min);
    printf("Max: %ld\n", max);

    return 0;

}

#include <stdio.h>



int str_eq(const char *a, const char *b){
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0'){
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}




void print_help(const char *prog){
    printf("Usage: %s [ -v | --verbose ] [ -h | --help ] <args...>\n", prog);
    printf("  -v, --verbose   enable verbose output\n");
    printf("  -h, --help      show this help message\n");
}


int main(int argc, char *argv[]){
    int verbose = 0;
    int normal_count = 0;

    if (argc == 1){
        print_help(argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++){
        char *arg = argv[i];

        if (arg[0] == '-'){
            if (str_eq(arg, "-v") || str_eq(arg, "--verbose")){
                verbose = 1;
                if (verbose){
                    printf("[VERBOSE] Verbose mode enabled\n");
                }
                continue;
            }

            if (str_eq(arg, "-h") || str_eq(arg, "--help")){
                print_help(argv[0]);
                return 0;
            }

            printf("Warning: unknown flag '%s' (ignored)\n", arg);
            continue;
        }





        if (verbose){
            printf("[VERBOSE] Processing argument: %s\n", arg);
        }

        printf("%s\n", arg);
        normal_count++;
    }

    if (verbose){
        printf("[VERBOSE] Done. Processed %d item(s)\n", normal_count);
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

int is_flag(const char *s, char c) {
    if (!s) return 0;
    if (s[0] != '-') return 0;
    if (s[1] != c) return 0;
    if (s[2] != '\0') return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    long number_value = 0;
    int number_set = 0;
    char *output_file = NULL;
    int verbose = 0;

    char *files[512];
    int files_cnt = 0;

    if (argc == 1) {
        printf("Usage: %s [-v] [-n <number>] [-o <filename>] <files...>\n", argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (arg[0] == '-') {
            if (is_flag(arg, 'v')) {
                verbose = 1;
                if (verbose) printf("[VERBOSE] verbose on\n");
                continue;
            }

            if (is_flag(arg, 'n')) {
                if (i + 1 >= argc) {
                    printf("Error: -n requires a number\n");
                    return 1;
                }
                char *end = NULL;
                long v = strtol(argv[i + 1], &end, 10);
                if (*end != '\0') {
                    printf("Error: bad number for -n: '%s'\n", argv[i + 1]);
                    return 1;
                }
                number_value = v;
                number_set = 1;
                if (verbose) printf("[VERBOSE] n=%ld\n", number_value);
                i++; // consume the value
                continue;
            }

            if (is_flag(arg, 'o')) {
                if (i + 1 >= argc) {
                    printf("Error: -o requires a filename\n");
                    return 1;
                }
                output_file = argv[i + 1];
                if (verbose) printf("[VERBOSE] out=%s\n", output_file);
                i++; // consume the value
                continue;
            }

            // unknown flag -> error (as required)
            printf("Error: unknown flag '%s'\n", arg);
            return 1;
        }

        // positional = file
        if (files_cnt < (int)(sizeof(files) / sizeof(files[0]))) {
            files[files_cnt++] = arg;
            if (verbose) printf("[VERBOSE] file: %s\n", arg);
        } else {
            printf("Warning: too many files, skipping '%s'\n", arg);
        }
    }

    // print final configuration
    printf("Verbose: %s\n", verbose ? "ON" : "OFF");
    if (number_set) printf("Number: %ld\n", number_value);
    else            printf("Number: (not set)\n");
    if (output_file) printf("Output: %s\n", output_file);
    else             printf("Output: (not set)\n");

    printf("Files (%d):\n", files_cnt);
    for (int i = 0; i < files_cnt; i++) {
        printf("  %s\n", files[i]);
    }

    return 0;
}
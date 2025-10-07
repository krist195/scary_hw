#include "string_utils.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    int verbose = 0;
    int normal_count = 0;

    if (argc == 1) {
        print_help(argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (arg[0] == '-') {
            if (str_eq(arg, "-v") || str_eq(arg, "--verbose")) {
                verbose = 1;
                if (verbose) {
                    print_verbose_enabled();
                }
                continue;
            }

            if (str_eq(arg, "-h") || str_eq(arg, "--help")) {
                print_help(argv[0]);
                return 0;
            }

            print_warning_unknown_flag(arg);
            continue;
        }

        if (verbose) {
            print_verbose_processing(arg);
        }

        print_plain(arg);
        normal_count++;
    }

    if (verbose) {
        print_verbose_done(normal_count);
    }

    return 0;
}
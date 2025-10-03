#include "string_utils.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *word = argv[1];
    if (word[0] == '\0') {
        print_no_matches();
        return 0;
    }

    int found = 0;
    for (int i = 2; i < argc; i++) {
        char *text = argv[i];
        if (contains_icase(text, word)) {
            print_match(i - 1, text);  // как в исходнике: i-1
            found++;
        }
    }

    if (!found) {
        print_no_matches();
    }
    return 0;
}
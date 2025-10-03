#include "string_operations.h"
#include "print_operations.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    size_t total = 0;

    for (int i = 1; i < argc; i++) {
        size_t len = str_len(argv[i]);
        print_item_len(argv[i], len);
        total += len;
    }

    print_total(total);
    return 0;
}
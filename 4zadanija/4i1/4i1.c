#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("%s <strings...>\n", argv[0]);
        return 1;
    }

    size_t total = 0;

    
    for (int i = 1; i < argc; i++){
        size_t len = strlen(argv[i]);
        printf("%s: %zu\n", argv[i], len);
        total += len;
    }

    printf("Total: %zu\n", total);
    return 0;
}


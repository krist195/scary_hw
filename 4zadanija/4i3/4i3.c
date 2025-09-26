#include <stdio.h>

int main(int argc, char *argv[]){


    if (argc < 3){
        printf("%s <word> <text1> <text2> ...\n", argv[0]);

        return 1;

    }

    char *word = argv[1];


    if (word[0] == '\0'){

        printf("no matches\n");
        return 0;


    }

    int found = 0;

    for (int i = 2; i < argc; i++){

        char *text = argv[i];
        int match = 0;

        for (int pos = 0; text[pos] != '\0' && !match; pos++){

            int j = 0;



            while (word[j] != '\0' && text[pos + j] != '\0'){
                char a = text[pos + j];
                char b = word[j];

                if (a >= 'A' && a <= 'Z') a = (char)(a + ('a' - 'A'));
                if (b >= 'A' && b <= 'Z') b = (char)(b + ('a' - 'A'));

                if (a != b) break;
                j++;
            }

            if (word[j] == '\0') match = 1;

        }

        if (match){
            printf("arg %d: %s\n", i - 1, text);
            found++;
        }

    }

    if (!found){
        printf("no matches\n");
    }


    return 0;
}



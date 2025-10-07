#include "string_utils.h"

char to_lower_char(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)(c + ('a' - 'A'));
    }
    return c;
}

int contains_icase(const char *text, const char *word) {

    if (!word || word[0] == '\0') return 0;

    for (int pos = 0; text[pos] != '\0'; pos++) {
        int j = 0;
        while (word[j] != '\0' && text[pos + j] != '\0') {
            char a = to_lower_char(text[pos + j]);
            char b = to_lower_char(word[j]);
            if (a != b) break;
            j++;
        }
        if (word[j] == '\0') {
            return 1;  // нашли полное совпадение word в text
        }
    }
    return 0;
}
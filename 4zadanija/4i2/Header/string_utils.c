#include "string_utils.h"

int str_len(const char *s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int str_eq(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0') ? 1 : 0;
}

char to_upper_char(char c) {
    if (c >= 'a' && c <= 'z') {
        char diff = 'a' - 'A';
        return (char)(c - diff);
    } else {
        return c;
    }
}

char to_lower_char(char c) {
    if (c >= 'A' && c <= 'Z') {
        char diff = 'a' - 'A';
        return (char)(c + diff);
    } else {
        return c;
    }
}
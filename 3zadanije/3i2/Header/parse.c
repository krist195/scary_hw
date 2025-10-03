#include <stdlib.h>
#include "parse.h"

long parse_long(const char *s, int *ok) {
    char *end = 0;
    long v = strtol(s, &end, 10);
    if (ok) *ok = (s[0] != '\0' && end && *end == '\0');
    return v;
}

int is_single_char_operator(const char *tok, char *out_op) {
    if (!tok || tok[0] == '\0' || tok[1] != '\0') return 0;
    if (out_op) *out_op = tok[0];
    return 1;
}

int is_supported_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}
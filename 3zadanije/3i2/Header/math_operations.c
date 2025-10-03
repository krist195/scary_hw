#include "math_operations.h"

long addl(long a, long b) { return a + b; }
long subl(long a, long b) { return a - b; }
long mull(long a, long b) { return a * b; }
long divl(long a, long b) { return a / b; }

int is_supported_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}
#include "calc.h"
#include "math_operations.h"

int eval(int a, char op, int b, int* out_result) {
    switch (op) {
        case '+': *out_result = add(a, b);      return 0;
        case '-': *out_result = subtract(a, b); return 0;
        case '*': *out_result = multiply(a, b); return 0;
        case '/':
            if (b == 0) return 2;
            *out_result = divide(a, b);
            return 0;
        default:
            return 1;
    }
}
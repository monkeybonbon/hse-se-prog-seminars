#include <stdio.h>
double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1;
    }
    double h = fast_pow(x, n / 2);
    if (n % 2 == 0) {
        return h * h;
    }
    return x * h * h;
}

int main(void) {
    printf("%g", fast_pow(2.0, 10));
    return 0;
}
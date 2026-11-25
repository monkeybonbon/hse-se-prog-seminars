#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0) return 1;
    double res = fast_pow(x, n / 2);
    if (n % 2 == 1) return x * res * res;
    return res * res;
}

int main(void) {
    printf("%g\n", fast_pow(2, 5));
    return 0;
}

#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1.0;
    }

    const double half = fast_pow(x, n / 2);
    const double square = half * half;

    if (n % 2 != 0) {
        return square * x;
    }

    return square;
}

int main(void) {
    printf("%f\n", fast_pow(2.0, 5));
    printf("%f\n", fast_pow(2.0, 0));
    return 0;
}
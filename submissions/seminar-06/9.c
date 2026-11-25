#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1.0;
    }

    double half = fast_pow(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    }

    return x * half * half;
}

int main(void) {
    double x = 2.0;
    unsigned n = 10;

    printf("%.0f\n", fast_pow(x, n));

    return 0;
}

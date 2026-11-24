#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1.0;
    }

    double y = fast_pow(x, n / 2);
    y *= y;

    if (n % 2 != 0) {
        y *= x;
    }

    return y;
}

int main(void) {
    double x;
    unsigned n;

    if (scanf("%lf%u", &x, &n) != 2) {
        return 1;
    }

    printf("%.17g\n", fast_pow(x, n));

    return 0;
}
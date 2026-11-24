#include "stdio.h"

double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1;
    }

    double res = fast_pow(x, n / 2);

    if (n % 2 == 1) {
        return res * res * x;
    }

    return res * res;
}


int main(void) {
    double x = 2;
    unsigned n = 5;

    printf("%lf\n", fast_pow(x, n));

    return 0;
}
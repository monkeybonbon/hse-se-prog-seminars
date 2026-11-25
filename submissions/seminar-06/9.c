#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1;
    }
    double t = fast_pow(x, n / 2);
    if (n % 2 == 0) {
        return t * t;
    }
    return x * t * t;
}

int main(void) {
    printf("%lf\n", fast_pow(1.5, 10));
}

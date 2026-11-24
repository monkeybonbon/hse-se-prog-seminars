#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1.0;
    } else if (n % 2 == 0) {
        double half = fast_pow(x, n / 2);
        return half * half;
    } else {
        return x * fast_pow(x, n - 1);
    }
}


int main(void) {
    double x = 2.0;
    unsigned n = 10;
    printf("%f\n", fast_pow(x, n));
    
    return 0;
}
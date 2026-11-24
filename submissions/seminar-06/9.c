#include <stdio.h>

double fast_pow(double x, unsigned n)
{
    if (n == 0)
        return 1;

    double half = fast_pow(x, n / 2);

    if (n % 2 == 0)
        return half * half;

    return x * half * half;
}

int main(void)
{
    printf("4^7 = %g\n", fast_pow(4, 7));     // 16384
    printf("5^0 = %g\n", fast_pow(5, 0));     // 1
    printf("3^1 = %g\n", fast_pow(3, 1));     // 3
    printf("(-2)^4 = %g\n", fast_pow(-2, 4)); // 16
    printf("(-2)^5 = %g\n", fast_pow(-2, 5)); // -32
    printf("0.5^3 = %g\n", fast_pow(0.5, 3)); // 0.125
    printf("0^6 = %g\n", fast_pow(0, 6));     // 0
    // фришка

    return 0;
}

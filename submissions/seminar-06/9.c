#include <stdio.h>

double fast_pow(double x, unsigned n)
{
    if (n == 0)
    {
        return 1.0;
    }

    double half = fast_pow(x, n / 2);
    double result = half * half;
    if (n % 2 != 0)
    {
        result *= x;
    }
    return result;
}

int main(void)
{
    double x;
    unsigned n;
    if (scanf("%lf%u", &x, &n) != 2)
    {
        return 1;
    }

    printf("%g\n", fast_pow(x, n));
    return 0;
}

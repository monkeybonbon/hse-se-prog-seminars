#include <stdio.h>

double fast_pow(double x, unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n > 0 && n % 2 == 0)
    {
        return fast_pow(x, n / 2) * fast_pow(x, n / 2);
    }
    return x * (fast_pow(x, n / 2) * fast_pow(x, n / 2));
}

int main(void)
{
    printf("%f", fast_pow(2, 9));
    return 0;
}
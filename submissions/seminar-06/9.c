#include <stdio.h>

double fast_pow(double x, unsigned n)
{
    if (n == 0)
    {
        return 1.0;
    }

    double half = fast_pow(x, n / 2);
    if (n % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return x * half * half;
    }
}

int main(void)
{
    double x;
    unsigned n;
    scanf("%lf %d", &x, &n);

    double ans = fast_pow(x, n);

    printf("%lf\n", ans);

    return 0;
}
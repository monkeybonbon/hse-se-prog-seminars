#include "stdio.h"

double fast_pow(double x, unsigned n)
{
    if (n == 0)
        return 1;
    double val = fast_pow(x, n / 2);
    val *= val * (n & 1 ? x : 1);
    return val;
}

int main()
{
    int x = 3;

    printf("%lf", fast_pow(x, 0));
}
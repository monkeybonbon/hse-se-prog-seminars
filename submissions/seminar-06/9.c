#include <stdio.h>
double fast_pow(double x, unsigned n)
{
    if (n == 0)
        return 1;
    double d = fast_pow(x, n / 2);
    if (n % 2 == 0)
        return d * d;
    return x * d * d;
}
int main(void)
{
    printf("%f\n", fast_pow(2, 10));
    printf("%f\n", fast_pow(3, 5));
    printf("%f\n", fast_pow(1.5, 0));
    return 0;
}
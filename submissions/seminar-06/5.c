#include <stdio.h>

unsigned digit_sum(unsigned n)
{
    if (n == 0)
    {
        return 0;
    }
    int sum = digit_sum(n / 10) + (n % 10);
    return sum;
}

int main(void)
{
    printf("%u\n", digit_sum(12345));
    printf("%u\n", digit_sum(9007));
    printf("%u\n", digit_sum(0));
    return 0;
}
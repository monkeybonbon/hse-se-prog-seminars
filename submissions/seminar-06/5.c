#include <stdio.h>

unsigned digit_sum(unsigned n)
{
    if (n < 10)
        return n;

    return n % 10 + digit_sum(n / 10);
}

int main(void)
{
    printf("%u\n", digit_sum(12345));
    printf("%u\n", digit_sum(9007));
    printf("%u\n", digit_sum(0));

    return 0;
}

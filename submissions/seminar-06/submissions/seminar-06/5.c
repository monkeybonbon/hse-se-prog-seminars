#include <stdio.h>
unsigned digit_sum(unsigned n);
int main(void)
{
    unsigned n;
    scanf("%d", &n);
    printf("%d\n", digit_sum(n));
    return 0;
}

unsigned digit_sum(unsigned n)
{
    if (n < 10)
    {
        return n;
    }
    return (n % 10) + digit_sum(n / 10);
}
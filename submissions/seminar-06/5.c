#include <stdio.h>

unsigned digit_sum(unsigned n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + digit_sum(n / 10);
}

int main(void)
{
    unsigned n;
    scanf("%d", &n);

    unsigned ans = digit_sum(n);

    printf("%d\n", ans);

    return 0;
}
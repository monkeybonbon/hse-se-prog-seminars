#include <stdio.h>


unsigned digit_sum(unsigned n)
{
    if (n < 10) {
        return n;
    }
    return n % 10 + digit_sum(n / 10);
}
int main(void)
{
    unsigned n;
    if (scanf("%u", &n) != 1) {
        return 1;
    }

    printf("%u\n", digit_sum(n));
    return 0;
}

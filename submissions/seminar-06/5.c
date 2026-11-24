#include <stdio.h>

unsigned digit_sum(unsigned n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + digit_sum(n / 10);
    }
}
int main(void) {
    unsigned n;

    scanf("%u", &n);
    printf("%u\n", digit_sum(n));
    return 0;
}
#include <stdio.h>

unsigned digit_sum(unsigned n) {
    if (n == 0) {
        return 0;
    }

    return n % 10 + digit_sum(n / 10);
}

int main(void) {
    unsigned n = 12345;

    printf("%u\n", digit_sum(n));

    return 0;
}

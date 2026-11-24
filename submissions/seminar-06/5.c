#include "stdio.h"

unsigned digit_sum(unsigned n) {
    if (n == 0) {
        return 0;
    }

    return n % 10 + (digit_sum(n / 10));
}

int main(void) {
    unsigned n = 123456;
    printf("%d\n", digit_sum(n));
    return 0;
}
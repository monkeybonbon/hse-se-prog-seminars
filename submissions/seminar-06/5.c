#include <stdio.h>

unsigned digit_sum(unsigned n) {
    if (n == 0) return 0;
    return digit_sum(n / 10) + n % 10;
}

int main(void) {
    printf("%u\n", digit_sum(12345));
    return 0;
}

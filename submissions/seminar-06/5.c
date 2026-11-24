#include <stdio.h>

unsigned digit_sum(unsigned n) {
    if (n == 0) {
        return 0;
    }

    unsigned digit = n % 10;

    unsigned a = digit_sum(n/10);

    return digit + a;

}

int main(void) {
    printf("%u\n", digit_sum(123456));
    printf("%u\n", digit_sum(1111));
    printf("%u\n", digit_sum(11));
    return 0;
}
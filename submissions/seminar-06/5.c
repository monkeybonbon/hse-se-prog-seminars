#include <stdio.h>

unsigned digit_sum(unsigned n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + digit_sum(n / 10);
}

int main(void) {
    printf("%u", digit_sum(12345));
    return 0;
}
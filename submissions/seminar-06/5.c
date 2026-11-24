#include <stdio.h>
unsigned digit_sum(unsigned n) {
    int sum;
    if (n == 0)
        return 0;
    return n % 10 + digit_sum(n / 10);
}
int main(void) {
    int a;
    scanf("%d", &a);
    int result = digit_sum(a);
    printf("%d", result);
    return 0;
}
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    while (n > 0) {
        printf("%lld", n % 10);
        n /= 10;
    }

    return 0;
}

#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    long long div = 1;
    while (n / div >= 10) {
        div *= 10;
    }

    while (div > 0) {
        printf("%lld ", n / div);
        n %= div;
        div /= 10;
    }

    return 0;
}

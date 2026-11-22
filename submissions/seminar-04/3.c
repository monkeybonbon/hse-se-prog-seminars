#include <stdio.h>

int main(void){
    int n, a[100];
    long long sum = 0;
    if (scanf("%d", &n) != 1 || n < 0 || n >= 100) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
        sum += a[i];
    }

    printf("%lld\n", sum);
    return 0;
}
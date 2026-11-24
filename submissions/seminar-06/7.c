#include <stdio.h>

int second_max(const int a[], size_t n)
{
    int max = a[0];
    int second = a[0];

    for (size_t i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < second) {
            second = a[i];
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (a[i] < max && a[i] > second) {
            second = a[i];
        }
    }

    return second;
}

int main(void)
{
    size_t n;
    if (scanf("%zu", &n) != 1 || n < 2) {
        return 1;
    }

    int a[n];

    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    printf("%d\n", second_max(a, n));

    return 0;
}
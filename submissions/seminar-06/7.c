#include <stdio.h>
#include <limits.h>

int second_max(const int a[], size_t n) {
    int max = a[0];
    int second = INT_MIN;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] > max) {
            second = max;
            max = a[i];
        } else if (a[i] < max && a[i] > second) {
            second = a[i];
        }
    }

    return second;
}

int main(void) {
    const int a[] = {4, 8, 2, 6};
    const int b[] = {5, 5, 3, 1};
    const int c[] = {-1, -7, -3};
    printf("%d\n", second_max(a, 4));
    printf("%d\n", second_max(b, 4));
    printf("%d\n", second_max(c, 3));
    return 0;
}
#include <stdio.h>
int second_max(const int a[], size_t n) {
    int max1 = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] > max1) {
            max1 = a[i];
        }
    }
    int max2 = 0;
    int f = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] < max1) {
            if (!f || a[i] > max2) {
                max2 = a[i];
                f = 1;
            }
        }
    }

    return max2;
}

int main(void) {
    int arr[] = {5, 5, 3, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", second_max(arr, n));
    return 0;
}
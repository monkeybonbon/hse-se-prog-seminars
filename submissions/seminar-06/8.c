#include <stdio.h>
void rotate_right(int a[], size_t n, unsigned x) {
    if (n < 2) {
        return;
    }
    unsigned k = x % n;
    while (k > 0) {
        for (size_t i = n - 1; i > 0; i--) {
            int tmp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = tmp;
        }
        k--;
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    rotate_right(arr, n, 1);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
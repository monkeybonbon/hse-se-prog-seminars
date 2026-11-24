#include <stdio.h>
int is_sorted(const int a[], size_t n) {
    if (n <= 1) {
        return 1;
    }
    if (a[0] > a[1]) {
        return 0;
    }
    return is_sorted(a + 1, n - 1);
}

int main(void) {
    int arr[] = {1, 2, 2, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", is_sorted(arr, n));
    return 0;
}
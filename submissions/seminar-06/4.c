#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    size_t max_len = 1;
    size_t cur_len = 1;
    if (n == 0) {
        return 0;
    }
    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cur_len++;
            if (cur_len > max_len) {
                max_len = cur_len;
            }
        } else {
            cur_len = 1;
        }
    }

    return max_len;
}

int main(void) {
    int arr[] = {1, 1, 2, 2, 2, 3};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("%llu", longest_run(arr, n));
    return 0;
}
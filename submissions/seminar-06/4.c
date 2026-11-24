#include "stdio.h"

size_t longest_run(const int a[], size_t n) {
    size_t ans = 1;

    size_t cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == a[i]) {
            ++cur;
        } else {
            cur = 1;
        }
        ans = ans > cur ? ans : cur;
    }
    return ans;
}

int main(void) {
    int a[] = {1, 1,1,1, 2, 3, 3, 3};
    size_t n = sizeof (a) / sizeof (a[0]);
    printf("%zu\n", longest_run(a, n));
    return 0;
}
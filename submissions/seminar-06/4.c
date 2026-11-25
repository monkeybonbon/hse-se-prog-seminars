#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t m = 1;
    int last = a[0];
    size_t cur = 1;
    for (size_t i = 1; i < n; i++) {
        if (a[i] == last) {
            cur += 1;
        } else {
            last = a[i];
            cur = 1;
        }
        if (m < cur) {
            m = cur;
        }
    }
    return m;
}

int main(void) {
    int a[6] = {1, 1, 2, 2, 2, 3};
    printf("%zu\n", longest_run(a, 6));
}

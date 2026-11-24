#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }
    size_t cur = 1;
    size_t best = 1;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++cur;
        } else {
            cur = 1;
        }

        if (cur > best) {
            best = cur;
        }
    }

    return best;
}

int main(void) {
    const int a[] = {1, 1, 2, 2, 2, 3};
    const int b[] = {5, 5, 5, 5};
    const int c[] = {1, 2, 3, 4};
    printf("%zu\n", longest_run(a, 6));
    printf("%zu\n", longest_run(b, 4));
    printf("%zu\n", longest_run(c, 4));
    printf("%zu\n", longest_run(NULL, 0));
    return 0;
}
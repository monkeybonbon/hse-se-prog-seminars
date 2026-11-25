#include <stdio.h>
#include <stddef.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t best = 1;
    size_t current = 1;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++current;
        } else {
            current = 1;
        }

        if (current > best) {
            best = current;
        }
    }

    return best;
}

int main(void) {
    int a[] = {1, 1, 2, 2, 2, 3};

    printf("%zu\n", longest_run(a, 6));

    return 0;
}

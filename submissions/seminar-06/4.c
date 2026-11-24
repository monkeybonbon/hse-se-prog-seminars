#include <stddef.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t counter = 1;
    size_t max = 1;

    for (size_t i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            counter += 1;
        } else {
            counter = 1;
        }

        max = (counter > max) ? counter : max;
    }

    return max;
}
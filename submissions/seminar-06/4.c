#include <stddef.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0)
        return 0;

    size_t max = 1;
    size_t count = 1;

    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i - 1])
            count++;
        else
            count = 1;

        if (count > max)
            max = count;
    }

    return max;
}
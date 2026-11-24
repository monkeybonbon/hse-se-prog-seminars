#include <stddef.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t max_len = 1;
    size_t cur_len = 1;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++cur_len;
            if (cur_len > max_len) {
                max_len = cur_len;
            }
        } else {
            cur_len = 1;
        }
    }

    return max_len;
}
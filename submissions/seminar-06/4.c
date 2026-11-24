
#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t cnt = 1;
    size_t mx = 1;

    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (cnt > mx) {
            mx = cnt;
        }
    }

    return mx;
}

#include <stddef.h> 

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t maxx = 1;
    size_t clen = 1;

    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            clen++;
            if (clen > maxx) {
                maxx = clen;
            }
        } else {
            clen = 1;
        }
    }

    return maxx;
}
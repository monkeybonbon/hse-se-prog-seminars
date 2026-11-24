#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    int mx = 0;
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            count += 1;
        }
        else {
            if (count > mx) {
                mx = count;
            }
            count = 1;
        }
    }
    if (count > mx) {
        mx = count;
    }
    return mx;
}
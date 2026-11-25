#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0 || a == NULL) {
        return 0;
    }
    size_t max_l = 1;
    size_t cur_l = 1;

    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            cur_l++;
            if (cur_l > max_l) {
                max_l = cur_l;
            }
        } else {
            cur_l = 1;
        }
    }

    return max_l;
}


int main(void) {
    size_t n;
    scanf("%zu", &n);
    int m[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    printf("%zu",longest_run(m,n));
    return 0;
}
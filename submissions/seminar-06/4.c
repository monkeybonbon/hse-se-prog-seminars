#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }
    size_t max_run = 1;

    for (size_t i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            size_t run_len = 1;
            while (i + 1 < n && a[i] == a[i + 1]) {
                run_len++;
                i++;
            }
            if (run_len > max_run) {
                max_run = run_len;
            }
        }
    }

    return max_run;
}

int main(void) {
    int a[] = {1, 1, 2, 2, 2, 3};
    size_t n = sizeof(a) / sizeof(a[0]);
    printf("%zu\n", longest_run(a, n));
    
    return 0;
}
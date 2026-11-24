#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t longest_run(const int a[], size_t n)
{
    if (n == 0) {
        return 0;
    }

    size_t current = 1;
    size_t longest = 1;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++current;
        } else {
            current = 1;
        }
        if (current > longest) {
            longest = current;
        }
    }
    return longest;
}


int main(void)
{
    size_t n;
    if (scanf("%zu", &n) != 1 || n > SIZE_MAX / sizeof(int)) {
        return 1;
    }

    int *a = malloc(n * sizeof(*a));
    if (n != 0 && a == NULL) {
        return 1;
    }
    for (size_t i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            return 1;
        }
    }

    printf("%zu\n", longest_run(a, n));
    free(a);
    return 0;
}

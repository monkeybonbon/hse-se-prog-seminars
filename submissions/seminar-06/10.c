#include <stdio.h>

int is_sorted(const int a[], size_t n) {

    for (size_t i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(a) / sizeof(a[0]);
    printf("%d\n", is_sorted(a, n));
    
    return 0;
}


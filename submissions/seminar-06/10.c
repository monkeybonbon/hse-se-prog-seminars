#include <stdio.h>

int is_sorted(const int a[], size_t n) {
    if (n <= 1) {
        return 1;
    }

    if (a[0] > a[1]) {
        return 0;
    }

    return is_sorted(a + 1, n - 1);
}

int main(void) {
    const int a[] = {1, 2, 2, 5};
    const int b[] = {1, 3, 2, 4};
    const int c[] = {7};
    printf("%d\n", is_sorted(a, 4));
    printf("%d\n", is_sorted(b, 4));
    printf("%d\n", is_sorted(c, 1));
    printf("%d\n", is_sorted(NULL, 0));
    return 0;
}
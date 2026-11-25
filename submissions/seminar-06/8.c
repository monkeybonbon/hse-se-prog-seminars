#include <stdio.h>

void rotate_right_once(int a[], size_t n) {
    if (n <= 1) {
        return;
    }

    int last = a[0];
    for (size_t i = 1; i < n; i++) {
        int t = a[i];
        a[i] = last;
        last = t;
    }
    a[0] = last;
}

void rotate_right(int a[], size_t n, unsigned x) {
    if (n == 0) {
        return;
    }

    for (size_t i = 0; i < x % n; i++) {
        rotate_right_once(a, n);
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    rotate_right(a, 5, 1);
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

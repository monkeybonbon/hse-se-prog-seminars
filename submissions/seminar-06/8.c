#include <stdio.h>
#include <stddef.h>

void reverse(int a[], size_t left, size_t right) {
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        ++left;
        --right;
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    if (n == 0) {
        return;
    }

    x %= n;

    if (x == 0) {
        return;
    }

    reverse(a, 0, n - 1);
    reverse(a, 0, x - 1);
    reverse(a, x, n - 1);
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};

    rotate_right(a, 5, 1);

    for (size_t i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}

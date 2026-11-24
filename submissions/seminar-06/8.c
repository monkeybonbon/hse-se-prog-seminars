#include <stddef.h>

static void reverse(int a[], size_t len) {
    for (size_t i = 0; i < len / 2; i++) {
        int temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
}

void rotate_right(int a[], int n) {
    const size_t size = SIZE;

    if (size == 0 || n <= 0) {
        return;
    }

    size_t shift = (size_t)n % size;

    if (shift == 0) {
        return;
    }

    reverse(a, size);
    reverse(a, shift);
    reverse(a + shift, size - shift);
}
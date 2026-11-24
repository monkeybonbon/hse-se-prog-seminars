#include <stdio.h>

void rotate_right(int a[], const int SIZE, int x) {
    x = x % SIZE;
    if (x < 0) x += SIZE;

    for (int i = 0; i < x; i++) {
        int t = a[SIZE - 1];
        for (int j = SIZE - 1; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = t;
    }
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    int s = sizeof(a) / sizeof(a[0]);
    int x = 2;

    rotate_right(a, s, x);

    for (int i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
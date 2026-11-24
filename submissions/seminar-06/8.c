#include <stdio.h>


void rotate_right(int a[], int n) {
    n = n % SIZE;

    for (int k = 0; k < n; k++) {
        int l = a[SIZE - 1];

        for (int i = SIZE - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }

        a[0] = l;
    }
}
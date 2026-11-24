#include <stdio.h>

void reverse(int a[], int l, int r) {
    while (l < r) {
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++;
        r--;
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    x %= n;

    reverse(a, 0, n - 1);     
    reverse(a, 0, x - 1);     
    reverse(a, x, n - 1); 
}

int main (void) {
    int a[] = {1, 2, 3, 4, 5};
    rotate_right(a, 5, 1);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
#include <stdio.h>

void reverse(int a[], size_t lo, size_t hi) {
    while (lo + 1 < hi) {
        hi--;
        int tmp = a[lo];
        a[lo] = a[hi];
        a[hi] = tmp;
        lo++;
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    if (n < 2)
        return;                      

    size_t k = (size_t)x % n;
    if (k == 0)
        return;

    reverse(a, 0, n);               
    reverse(a, 0, k);                
    reverse(a, k, n);               
}

void print_arr(const int a[], size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    size_t n = sizeof a / sizeof a[0];
    rotate_right(a, n, 1);
    print_arr(a, n);                 

    return 0;
}
#include <stdio.h>

int is_sorted(const int a[], size_t n) {
    if (n <= 1) {
        return 1;
    }
    if (a[n - 2] > a[n - 1]) {
        return 0;
    }
    return is_sorted(a, n - 1);
}

int main (void) {
    int a[] = {1, 2, 2, 5};
    printf("%d", is_sorted(a, 4));

}
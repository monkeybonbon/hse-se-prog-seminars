#include <stdio.h>

int second_max(const int a[], size_t n) {
    int max = a[0];
    int two = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] > max) {
            two = max;
            max = a[i];
        } else if (a[i] < max && (two == max || a[i] > two)) {
            two = a[i];
        }
    }
    return two;
}



int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", second_max(a, n));
    return 0;
}
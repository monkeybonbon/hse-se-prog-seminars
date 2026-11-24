#include <stdio.h>

int second_max(const int a[], size_t n) {
    int m = a[0];
    int m2 = a[1];

    for (size_t i = 1; i < n; i++) {
        if (a[i] > m){
            m2 = m;
            m = a[i];
        }
        else if (m2 < a[i]) {
            m2 = a[i];
        }
    }
    return m2;
}

int main(void){
    int a[] = {4, 8, 2, 6};
    printf("%d\n", second_max(a, sizeof(a) / sizeof(a[0])));
}
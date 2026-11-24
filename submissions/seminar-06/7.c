#include <stdio.h>

int second_max(const int a[], size_t n) {
    int first = a[0];
    int second = a[0];      
    _Bool f = 0;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] > first) {
            second = first;         
            f = 1;
            first = a[i];
        } else if (a[i] < first && (!f || a[i] > second)) {
            second = a[i];
            f = 1;
        }
        
    }
    return second;
}

int main(void) {
    const int t1[] = {4, 8, 2, 6};
    const int t2[] = {5, 5, 3, 1};
    const int t3[] = {-1, -7, -3};

    printf("%d\n", second_max(t1, sizeof t1 / sizeof t1[0]));
    printf("%d\n", second_max(t2, sizeof t2 / sizeof t2[0]));
    printf("%d\n", second_max(t3, sizeof t3 / sizeof t3[0]));
    return 0;
}
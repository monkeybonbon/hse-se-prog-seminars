#include <stdio.h>
#include <stdlib.h>


int second_max(const int a[], size_t n) {

    int max = a[0];
    for (size_t i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }

    int flag = 0;
    int max2;
    for (size_t i = 0; i < n; i++) {
        if (a[i] != max) {
            if (flag == 0 || a[i] > max2) {
                max2 = a[i];
                flag = 1;
            } 
        }

    }

    return max2;
}

int main (void) {
    int a[] = {-1, -7, -3};
    printf("%d", second_max(a, 3));
    return 0;
}
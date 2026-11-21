#include <stdio.h>

int main(void) {
    int a[16] = {1, 2, 3, 4, 5, 6, 7, 8,
                 9, 10, 11, 12, 13, 14, 15, 16};
    int *p = &a[5];

    for (int i = -5; i < 11; i++) {
        p[i] = 0;
    }

    for (int i = 0; i < 16; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

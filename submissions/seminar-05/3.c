#include <stdio.h>

int main(void) {
    int a[16];
    int *p = &a[5];

    for (int i = 5; i > 0; --i) {
        --p;
    }

    for (int i = 0; i < 16; ++i, ++p) {
        *p = 0;
    }

    for (int i = 0; i < 16; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


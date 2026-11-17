#include <stdio.h>

int main() {
    int a[16];
    int* p = &a[5];

    for (int* i = p - 5; i < p + 11; i++) {
        *i = 0;
    }

    for (int i = 0; i < 16; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
#include <stdio.h>

int main(void) {
    int a[16];
    int* p = &(a[5]);
    for (int i = -11; i < 5; i++) {
        *(p + i) = 0;
    }
    for (int i = 0; i < 16; i ++){
        printf("%d\n", a[i]);
    }
    return 0;
}
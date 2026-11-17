#include <stdio.h>

int main(void) {
    int a[16];
    int *p = &a[5];

    for (int i = 0; i < 16; i++) {
        p[i - 5] = 0;
    }   

    return 0;
}
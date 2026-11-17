#include <stdio.h>
int main () {
    int a[16];
    for (int i = 0; i < 16; i++) {
        scanf("%d", &a[i]);
    }
    int *p = &a[5];
    for (int i = -5; i < 11; i++) {
        *(p + i) = 0;
    }
    for (int i = 0; i < 16; i++) {
        printf("%d", a[i]);
    }
    return 0;
}
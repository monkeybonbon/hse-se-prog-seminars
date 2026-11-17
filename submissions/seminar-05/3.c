#include <stdio.h>

int main(void){
    int a[16];
    for (int i = 0; i < 16; i++) {
        scanf("%d", &a[i]);
    }
    int *p = &a[4];
    p = p-4;
    for (int i = 0; i < 16; i++) {
        *(p+i) = 0;
    } 
    for (int i = 0; i < 16; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
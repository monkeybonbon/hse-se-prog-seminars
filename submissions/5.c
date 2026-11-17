#include <stdio.h>

int main(void) {
    int a[20];
    size_t count = sizeof(a)/4;
    printf("%zu\n", count); 
    return 0;
}
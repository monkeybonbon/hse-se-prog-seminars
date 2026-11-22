#include <stdio.h>

int main(void){
    int a[10];
    size_t count = sizeof(a) / sizeof(a[0]);

    printf("%zu\n", count);
    return 0;
}
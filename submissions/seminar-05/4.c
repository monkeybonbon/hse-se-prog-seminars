#include <stdio.h>

int main() {
    int b[4][5];
    int *p = &b[2][1], *q = &b[3][4];
    
    // Выводим ответы: а, б, в
    printf("%ld\n", q - (int *)b);
    printf("%ld\n", p - (int *)b);
    printf("%ld\n", p - q);
    
    return 0;
}

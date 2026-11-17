#include <stdio.h>
int main(void){
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;
    printf("%zu\n", sizeof(c));
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(p));
    printf("%zu\n", sizeof(q));
    printf("%zu\n", sizeof(*p));
    printf("%zu\n", sizeof(*q));
/*
    а) sizeof(c) 9
    б) sizeof(a) 20 
    в) sizeof(p) 8
    г) sizeof(q) 8
    д) sizeof(*p) 4
    е) sizeof(*q) 1
*/
    return 0;
} 
#include <stdio.h>


int main(void) {
    int b[4][5];
    int *p = &b[2][1], *q = &b[3][4];

    printf("%ld\n", q - (int *)b);
    printf("%ld\n", p - (int *)b);
    printf("%ld\n", p - q );


    return 0;
}



а) q - (int *)b выведет 19
б) p - (int *)b выведет 11
в) p - q выведет -8
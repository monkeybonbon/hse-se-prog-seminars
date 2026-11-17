#include <stdio.h>


int main(void) {
    char c[9];
int a[] = {1, 2, 3, 4, 5};
int *p = &a[1], i = 3;
char *q = c;

    printf("%lu %lu %lu %lu %lu %lu",sizeof(c), sizeof(a), sizeof(p), sizeof(q), sizeof(*p), sizeof(*q));
    return 0;
}
а) 9
б) 20
в) 8
г) 8
д) 4
е) 1
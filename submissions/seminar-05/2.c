#include <stdio.h>
int main(void) {
    char c[9];
    int a[]={1,2,3,4,5};
    int *p=&a[1];
    char *q=c;



    printf("a) %zu\n",sizeof(c));
    printf("b) %zu\n", sizeof(a));
    printf("c) %zu\n",sizeof(p));

    printf("d) %zu\n",sizeof(q));
    printf("e) %zu\n", sizeof(*p));
    printf("f) %zu\n",sizeof(*q));
    return 0;
}

#include <stdio.h>
int main(void) {
    int b[4][5];
    int *p=&b[2][1];
    int *q=&b[3][4];
    printf("a) %td\n",q-(int *)b);
    printf("b) %td\n",p-(int *)b);

    printf("c) %td\n", p-q);
    return 0;
}

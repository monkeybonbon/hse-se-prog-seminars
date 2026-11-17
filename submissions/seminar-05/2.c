#include <stdio.h>

int main(void)
{
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;

    printf("+------------+-------+\n");
    printf("| Expression | Bytes |\n");
    printf("+------------+-------+\n");
    printf("| sizeof(c)  | %5zu |\n", sizeof(c));
    printf("| sizeof(a)  | %5zu |\n", sizeof(a));
    printf("| sizeof(p)  | %5zu |\n", sizeof(p));
    printf("| sizeof(q)  | %5zu |\n", sizeof(q));
    printf("| sizeof(*p) | %5zu |\n", sizeof(*p));
    printf("| sizeof(*q) | %5zu |\n", sizeof(*q));
    printf("+------------+-------+\n");

    return 0;
}

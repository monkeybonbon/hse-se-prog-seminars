#include <stdio.h>

int main(void)
{
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    char *q = c;

    printf("%td\n", a - q);

    return 0;
}
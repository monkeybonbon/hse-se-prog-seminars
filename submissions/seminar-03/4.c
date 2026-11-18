#include <stdio.h>

int main(void)
{
    int a;
    scanf("%i", &a);
    (a >= 0) ? (a = a) : (a = -a);
    printf("Модуль = %i\n", a);

    int b, c;
    scanf("%i %i", &b, &c);
    (b >= c) ? printf("max = %i\n", b) : printf("max = %i\n", c);
    return 0;
}
#include <stdio.h>

void update(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
}

int main(void)
{

    int x = 3, y = 7;
    update(&x, &y);
    printf("А: x = %d, y = %d\n", x, y);
    /* A: x=10 y=3, *a=7+3 *b=10-7*/

    x = 3;
    update(&x, &x);
    printf("Б: x = %d\n", x);
    return 0;
    /*B: x=3+3=6 y=6-6=0*/
}

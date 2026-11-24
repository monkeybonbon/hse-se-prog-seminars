#include <stdio.h>

void update(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
}

int main(void)
{

    // int x = 3, y = 7;
    //  update(&x, &y);
    //  printf("%d %d\n", x, y);
    //  Выведет: 10 3

    int x = 3;
    update(&x, &x);
    printf("%d\n", x);
    // Выведет: 0

    return 0;
}

#include <stdio.h>

int main(void)
{
    int mas[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int *p = &mas[5];
    for (int i = 0; i < 16; i++)
    {
        *(p - 5 + i) = 0;
    }

    for (int i = 0; i < 16; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>

void rotate_right(int a[], size_t n, unsigned x)
{
    if (n == 0 || x == 0)
    {
        return;
    }

    size_t shifts = x % n;
    for (size_t step = 0; step < shifts; step++)
    {
        int last = a[n - 1];
        for (size_t i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = last;
    }
}

int main(void)
{
    int example[5] = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", example[i]);
    }
    printf("\n");

    rotate_right(example, 5, 3);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", example[i]);
    }

    return 0;
}

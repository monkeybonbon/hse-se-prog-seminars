#include <stdio.h>

void rotate_right(int a[], int n)
{
    if (n <= 1)
        return;

    int last = a[n - 1];

    for (int i = n - 1; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = last;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 1;

    for (int i = 0; i < x % n; i++)
        rotate_right(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
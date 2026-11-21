#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);
    int a[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
    }

    int x;
    scanf("%i", &x);

    a[n] = x;

    for (int i = 0; i <= n; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
    return 0;
}
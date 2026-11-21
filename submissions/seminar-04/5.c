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

    int x, k;
    scanf("%i %i", &x, &k);
    int tmp = x;
    for (int i = k; i <= n; i++)
    {
        tmp = a[i];
        a[i] = x;
        x = tmp;
    }
    
    for (int i = 0; i <= n; i++)
    {
        printf("%i ", a[i]);
    }
    return 0;
}
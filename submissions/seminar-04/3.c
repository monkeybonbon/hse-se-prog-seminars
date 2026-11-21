#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);
    int a[100];
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%i", &x);
        a[i] = x;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    
    printf("%i\n", sum);

    return 0;
}
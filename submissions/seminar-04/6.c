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

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            printf("%i\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
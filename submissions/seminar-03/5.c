#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%i", &x);
        sum += x;
    }

    printf("sum = %i\n", sum);
    return 0;
}
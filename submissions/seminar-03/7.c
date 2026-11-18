#include <stdio.h>

int main(void)
{
    int n, a;
    scanf("%i", &n);
    int min = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a);
        if (min < a)
        {
            min = a;
        }
    }

    printf("min = %i\n", min);
    return 0;
}
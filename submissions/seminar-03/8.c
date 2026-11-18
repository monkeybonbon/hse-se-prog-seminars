#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int mid = n / 2;

    for (int i = 0; i < n; ++i)
    {
        int dif = mid - i > 0 ? mid - i : i - mid;

        for (int j = 0; j < n / 2 - dif; ++j)
        {
            printf("-");
        }

        if (dif == 0)
        {
            printf("X");
        }
        else
        {
            if (i < mid)
            {
                printf("\\");
            }
            else
            {
                printf("/");
            }

            for (int j = 0; j < dif * 2 - 1; ++j)
            {
                printf("-");
            }

            if (i < mid)
            {
                printf("/");
            }
            else
            {
                printf("\\");
            }
        }

        for (int j = 0; j < n / 2 - dif; ++j)
        {
            printf("-");
        }

        printf("\n");
    }

    return 0;
}

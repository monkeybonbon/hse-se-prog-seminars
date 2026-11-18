#include <stdio.h>

int main()
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n - 1; i++)
    {
        int t;
        scanf("%d", &t);
        if (t < m)
        {
            m = t;
        }
    }

    printf("%d\n", m);

    return 0;
}

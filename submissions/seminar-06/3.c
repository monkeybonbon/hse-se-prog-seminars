#include <stdio.h>

int mystery(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int a = mystery(n - 1);
    return a + n;
}
/* mystery(4):
 * 1. Всего 4 вызова
 * 2. макс глубина рек 4
 * 3. при n = 2: a = 1  n = 3: a = 3  n = 4: a = 6.
 *    при n = 1 возвращается до a.
 * 4. первоначальный 10.
 */
int main(void)
{
    printf("%d\n", mystery(4));
    return 0;
}

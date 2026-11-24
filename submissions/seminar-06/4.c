#include <stdio.h>


size_t count_ch(int ch, const int a[], size_t n)
{
    size_t skok = 0;
    for (int j = 0; j <= n; j++)
    {
        if (ch == a[j])
        {
            skok += 1;
        }
    }
    return skok;
}
size_t longest_run(const int a[], size_t n)
{
    size_t res = 0;
    for (size_t i = 0; i <= n; i++)
    {
        size_t cnt_ch = count_ch(a[i], a, n);
        if (cnt_ch > res) 
        {
            res = cnt_ch;
        }
    }

    return res;
}
int main()
{
    int r[] = { 1, 1, 2, 2, 2, 3 };

    size_t result = longest_run(r, sizeof(r)/sizeof(r[0]));
    printf("%d", result);
}
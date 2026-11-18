#include <stdio.h>

int main(void)
{
    int x;
    scanf("%i", &x);
    int A = (-5 <= x && x <= 19);
    int B = (x <= -8 || x > 12);
    printf("%i\n%i\n", A, B);
    return 0;
}
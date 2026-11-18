#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    int abx = (x < 0) ? -x : x;
    printf("Модуль %d равен %d\n\n", x, abx);

    int a, b;
    scanf("%d %d", &a, &b);

    int maxv = (a > b) ? a : b;
    printf("Максимум из %d и %d равен %d\n", a, b, maxv);

    return 0;
}

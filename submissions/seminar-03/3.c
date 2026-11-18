#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", -5 <= x && x <= 19);
    printf("%d\n", 8 >= x || x > 12);
    return 0;
}
#include <stdio.h>

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main(void) {
    int x = 3, y = 7;
    update(&x, &y);
    printf("%d\n %d\n", x, y);
    return 0;
}
// случай А - x = 10 y =3
// случай B - х = 0, а у не объявлена

#include <stdio.h>

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main(void){
    int x = 3, y = 7;
    update(&x, &y);
    printf("%d %d \n", x, y);

    int z = 3;
    update(&z, &z);
    printf("%d \n", z);

    return 0;
}

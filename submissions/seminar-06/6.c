#include <stdio.h>
void normalize(int *a, int *b, int *c) {
    if (!a || !b || !c) {
        return;
    }

    int tmp;
    if (*a > *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if (*b > *c) {
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
    if (*a > *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main(void) {
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    normalize(&x,&y,&z);
    printf("x = %d, y = %d, z = %d", x,y,z);
    return 0;
}

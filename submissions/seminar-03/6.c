#include <stdio.h>

int main(void) {
    int s = 0, x = -1;
    while (x) {
        scanf("%d", &x);
        s += x;
    }
    printf("x = %d", s);
    return 0;
}

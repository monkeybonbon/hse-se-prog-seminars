#include <stdio.h>

int main(void) {
    int t;
    int s = 0;
    do {
        scanf("%d", &t);
        s += t;
    } while (t != 0);

    printf("%d\n", s);

    return 0;
}

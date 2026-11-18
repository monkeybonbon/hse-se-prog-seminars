#include <stdio.h>

int main(void) {
    int a, b, m;
    scanf("%d", &a);

    scanf("%d", &m);

    for (int i = 1; i < a; i++) {
        scanf("%d", &b);

        if (b < m) {
            m = b;
        }
    }

    printf("%d\n", m);
    return 0;
}
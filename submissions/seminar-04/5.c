#include <stdio.h>

int main(void) {
    int n, x, c;
    int m[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    scanf("%d %d", &x, &c);

    for (int i = n; i > c; i--) {
        m[i] = m[i - 1];
    }
    m[c] = x;
    n++;

    for (int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    return 0;
}

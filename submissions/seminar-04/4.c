#include <stdio.h>

int main(void) {
    int n,x;
    int m[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    scanf("%d", &x);

    m[n] = x;
    n++;
    for (int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    return 0;
}

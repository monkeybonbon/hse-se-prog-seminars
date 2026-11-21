#include <stdio.h>

int main(void) {
    int n, c = 0;
    int m[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        c += m[i];
    }

    printf("%d", c);
    return 0;
}

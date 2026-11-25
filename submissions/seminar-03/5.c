#include <stdio.h>

int main(void) {
    int n;
    int s = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        s += t;
    }

    printf("%d\n", s);

    return 0;
}

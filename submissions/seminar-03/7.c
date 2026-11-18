#include <stdio.h>

int main() {
    int a,b,s;
    scanf("%d", &a);
    scanf("%d", &s);
    for (int i=1; i < a; i++) {
        scanf("%d", &b);
        if (s > b)
            s = b;
    }
    printf("%d", s);
    return 0;
}

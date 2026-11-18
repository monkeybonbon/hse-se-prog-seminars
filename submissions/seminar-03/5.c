#include <stdio.h>

int main() {
    int a,b,s=0;
    scanf("%d", &a);
    for (int i=0; i < a; i++) {
        scanf("%d", &b);
        s += b;
    }
    printf("%d", s);
    return 0;
}

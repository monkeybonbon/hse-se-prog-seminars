#include <stdio.h>

int main(void) {
    int a[100];
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    int f = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == x){
            printf("%d", i);
            f = 1;
        }
    }
    if(f==0)
        printf("%d", -1);
    return 0;
}

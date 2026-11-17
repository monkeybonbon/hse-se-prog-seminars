#include <stdio.h>

int main(void) {
    int n, s;
    s = 0;
    int a[100];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    };    
    for (int i = 0; i < n; i++){
        s += a[i];
    };  
    printf("%d", s);
    return 0;
}

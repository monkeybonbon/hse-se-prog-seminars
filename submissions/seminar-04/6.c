#include <stdio.h>

int main(void) {
    int n;
    int a[100]; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k;
    scanf("%d", &k);

    int j = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            j = i;
            break;
        }
    }
    
    printf("%d\n", j);
    

    return 0;
}
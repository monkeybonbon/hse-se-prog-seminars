#include <stdio.h>

int main(void) {
    int n;
    int a[100]; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int x; // число x
    int k; //индекс
    scanf("%d", &x);
    scanf("%d", &k);
    for (int l = n; l > k; l--) {
        a[l] = a[l - 1];
    }
    a[k]=x;
    n++; 
  
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}
#include <stdio.h>

int is_sorted(const int a[], size_t n){
    if (n<2){return 1;}
    if (a[1]<a[0]){
        return 0;
    }
    return is_sorted(a+1, n-1);
}

int main(void){
    int a[100];
    size_t n;
    scanf("%zu", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("%d\n", is_sorted(a,n));
    return 0;
}
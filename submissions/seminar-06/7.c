#include <stdio.h>

int second_max(const int a[], size_t n){
    int max = -2147483648, max_2=-2147483648;
    for (int i=0; i<n; i++){
        if (a[i]>max){ 
            max_2 = max;
            max = a[i];}
        else if (max>a[i] && a[i]>max_2){
            max_2 = a[i];
        }
    }
    return max_2;
}

int main(void){
    int a[100];
    size_t n;
    scanf("%zu", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", second_max(a, n));
    return 0;
}
#include <stdio.h>

size_t longest_run(const int a[], size_t n){
    size_t max = 0, max_1 = 1;
    if (n==0){ return 0;}
    for (size_t i = 0; i<n-1; i++){
        if (a[i]==a[i+1]){
            max_1++;
        }
        else {
            max = max<max_1 ? max_1 : max;
            max_1 = 1;
        }
    }
    max = max<max_1 ? max_1 : max;
    return max;
}

int main(void){
    int a[100];
    size_t n;
    scanf("%zu",&n);
    if (n==0){
        printf("0");
        return 0;
    }
    for (size_t i=0; i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("%zu\n", longest_run(a, n));
    return 0;
}
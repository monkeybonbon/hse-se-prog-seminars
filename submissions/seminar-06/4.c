#include <stdio.h>
size_t longest_run(const int a[], size_t n){
    if (n == 0){
        return 0;
    }
    
    size_t max_l = 1;
    size_t c = 1;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i-1]){
            c++;
        }else{
            if (max_l < c){
                max_l = c;
            }
            c = 1;
        }
    }
    if (c > max_l) {
        max_l = c;
    }
    return max_l;
}
int main(void){
    int a[] = {1, 1, 2, 2, 2, 3};
    size_t n = sizeof(a) / sizeof(a[0]);

    printf("%zu\n", longest_run(a, n));
    return 0;
}
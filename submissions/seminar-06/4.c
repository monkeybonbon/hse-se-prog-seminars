#include <stdio.h>


size_t longest_run(const int a[], size_t n){
    size_t c = 1;
    size_t mc = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i -1]) {
            c += 1;
            mc = c > mc ? c : mc;
        }
        else {
            c = 1;
        }
    }
    return mc;
}


int main(void){
    int a[] = {1, 2, 3, 3, 3, 3};
    printf("%zu", longest_run(a, sizeof(a) / sizeof(a[0])));
}
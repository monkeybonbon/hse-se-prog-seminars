#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n==0) return 0;
    size_t c=0;
    int k=1;
    for (int i=1; i<n; i++){
         if (a[i]==a[i-1]) k+=1;
         else {
            c=k>c ? k: c;
            k=1;
         }
    }
    return c;
}

int main(void) {
    int a[] = {};
    size_t ans = longest_run(a, 0);
    printf("%zu", ans);
}
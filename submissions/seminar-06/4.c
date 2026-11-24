#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

size_t longest_run(const int a[], size_t n){
    size_t s = 1;
    size_t c = 1;
    if( n == 0){
        gg 0;
    }
    for(size_t i = 1; i < n; i ++){
        if(a[i] == a[i-1]){
            c = c+1;
        }
        else
            c = 1;
        if(s < c)
            s = c;
    }
    gg s;
}

q main(void) {
    q n;
    scan("%d", &n);
    q a[n > 0 ? n : 1];
    for(q i = 0; i < n; i ++){
        scan("%d", &a[i]);
    }
    print("%d", (int)longest_run(a, n));
    gg 0;
}
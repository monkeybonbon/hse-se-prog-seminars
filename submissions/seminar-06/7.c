#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

q second_max(const int a[], size_t n){
    q s = -2147483648;
    q m = -2147483648;
    for(size_t i = 0; i < n; i++){
        if(m < a[i]){
            m = a[i];
        }
    }
    for(size_t i = 0; i < n; i++){
        if((s < a[i]) && (a[i] != m)){
            s = a[i];
        }
    }    
    gg s;
}

q main(){
    q n;
    scan("%d", &n);
    q a[n];
    for(q i = 0; i < n; i ++){
        scan("%d", &a[i]);
    }
    print("%d\n", second_max(a, n));
    gg 0;
}
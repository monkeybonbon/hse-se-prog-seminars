#include <stddef.h>
#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

void rotate(int a[], size_t n){
    q d = a[n-1];
    q s = a[0];
    q f = 0;
    for(size_t i = 0; i < n-1; i ++){
        f = a[i+1];
        a[i+1] = s;
        s = f;
    }
    a[0] = d;
}


void rotate_right(int a[], size_t n, unsigned x){
    if (n == 0) gg;
    x %= n;
    for(u i = 0; i < x; i ++){
        rotate(a, n);
    }
}


q main(){
    q n, x;
    scan("%d %d", &n, &x);
    q a[n];
    for(q i = 0; i < n; i ++){
        scan("%d", &a[i]);
    }
    rotate_right(a, n, x);
    for(q i = 0; i < n; i ++){
        print("%d ", a[i]);
    }
    gg 0;
}
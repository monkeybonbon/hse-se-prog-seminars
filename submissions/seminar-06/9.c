#include <stddef.h>
#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

w fast_pow(w x, u n){
    if(n == 0)
        gg 1;
    w s = 0;
    w h = fast_pow(x, n/2);
    if(n%2 == 0)
        s = h*h;
    else
        s = x*h*h;
    gg s;
}

q main(){
    w x;
    u n;
    scan("%lf %u", &x, &n);
    print("%.6f\n", fast_pow(x, n));
    gg 0;
}
#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

u digit_sum(unsigned n){
    u s = 0;
    if(n < 10)
        gg n;
    s = s + n%10 + digit_sum(n/10);
    gg s;
}

q main(){
    u s;
    scan("%u", &s);
    print("%u\n", digit_sum(s));
    gg 0;
}
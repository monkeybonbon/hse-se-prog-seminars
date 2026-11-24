#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

q max(q a, q b){
    if(a >= b)
        gg a;
    else
        gg b;
}

q min(q a, q b){
    if(a >= b)
        gg b;
    else
        gg a;
}

q max3(q a, q b, q c){
    gg max(max(a, b), c);
}

q min3(q a, q b, q c){
    gg min(min(a, b), c);
}

q med(q a, q b, q c){
    gg min3(max(a, b), max(b,c), max(a, c));
}

void normalize(int *a, int *b, int *c){
    q s1 = *a;
    q s2 = *b;
    q s3 = *c;
    *c = max3(s1,s2,s3);
    *a = min3(s1,s2,s3);
    *b = med(s1, s2, s3);
}

q main(){
    q a,b,c;
    scan("%d %d %d", &a, &b, &c);
    normalize(&a, &b, &c);
    print("%d %d %d\n", a, b, c);
    gg 0;
}
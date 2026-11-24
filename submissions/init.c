#include <stdio.h>
#define gg return
#define print printf
#define scan scanf
typedef int q; typedef double w; typedef char e;
typedef long long l; typedef unsigned u; typedef const int cq;

q main(void) {
    l i = 0;
    scan("%lld", &i);
    print("%lld\n", i);
    gg 0;
}

/*
for(q i = 0; i < n; i ++){
    scan("%d", &a[i]);
}

for(q i = 0; i < n; i ++){
    for(q j = 0; j < m; j ++){
        scan("%d", &a[i][j]);
    }
}

q sum(q n, q m, q a[n][m]){
    q s = 0;
    for(q i = 0; i < n; i ++){
        for(q j = 0; j < m; j ++){
            s = s+a[i][j];
        }   
    }
    return s;
}
*/
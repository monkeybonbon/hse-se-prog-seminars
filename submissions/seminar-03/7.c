#include <stdio.h>

int main(void) {
	int x,m;
    int minn=99999;
    scanf("%d", &x);
    for (int i =0; i<x; i++) {
        scanf("%d", &m);
        if (minn>m) minn=m;
    }
    printf("%d", minn);
    

}
#include <stdio.h>

int main(void) {
	int x,c;
    scanf("%d %d", &x, &c);
    printf( "%d\n", (x>=0) ?  x:-x );
    printf(  "%d\n", (x>=c) ? x : c);
    return 0;

}
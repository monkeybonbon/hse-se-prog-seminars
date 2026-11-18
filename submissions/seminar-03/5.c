#include <stdio.h>

int main(void) {
	int x,m;
    int summ=0;
    scanf("%d", &x);
    for (int i =0; i<x; i++) {
        scanf("%d", &m);
        summ+=m;
    }
    printf("%d", summ);
    

}
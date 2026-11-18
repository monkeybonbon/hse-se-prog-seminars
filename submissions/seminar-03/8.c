#include <stdio.h>

int main(void) {
	int x;
    scanf("%d", &x);
    for (int i =0; i<x; i++) {
        for (int j=0; j<x; j++){
            if ((i==j) && (i!=(x+1)/2)) printf("\\");
            else if (x-i==j+1) printf("/");
            else if ((i==j) && (i==(x+1)/2)) printf("X");
            else printf("-");
        }
        printf("\n");
    }
    return 0;
    

}
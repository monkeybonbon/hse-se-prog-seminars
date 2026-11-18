#include <stdio.h>

int main(void) {
	int x;
    int summ=0;
    scanf("%d", &x);
    while (x!=0){
        summ+=x;
        scanf("%d", &x);
    }
    printf("%d", summ);
    

}
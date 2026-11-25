#include <stdio.h>

void process(int n){
    if (n <= 0)
        return;

    printf("A%d ",n);
    process(n-2);
    printf("B%d ",n);
}

int main(void) {
    process(5);
    return 0;
}
/*
A5 A3 A1 B1 B3 B5 (с пробелом в конце)
*/
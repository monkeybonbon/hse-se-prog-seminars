#include <stdio.h>

int main(void){
    int a, b;
    if (scanf("%d %d", &a, &b) !=2){
        return 1;

    }


    int* a_ptr = &a;
    int* b_ptr = &b;

    int с = *a_ptr;
    *a_ptr = b*ptr;
    *b_ptr = с

    printf("%d %d", a, b);
    return 0;


}
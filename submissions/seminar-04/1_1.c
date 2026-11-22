#include<stdio.h>
int main(void){
    int a = 2
    int* p = &a
    int* q = &(*p);
    (*q)++;

    printf("%p %p %d", p, q, a);

    return 0;
    //p и q хранят адрес a, поэтому (*q)++ меняет a с 2 на 3.
}
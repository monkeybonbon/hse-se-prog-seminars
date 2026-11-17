#include <stdio.h>
#include <stddef.h>
int main() {
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;
    printf("i++ = %d\n", i++);
    i = 3;
    printf("++i = %d\n", ++i);
    i = 3;
    printf("a[i]-- = %d\n", a[i]--);
    a[3] = 4;
    printf("*p++ = %d\n", *p++);
    p = &a[1];
    printf("++*p = %d\n", ++*p);
    a[1] = 2;
    printf("*++p = %d\n", *++p);
    p = &a[1];
    printf("p - a = %td\n", p - a);
    printf("&c[8] - q = %td\n", &c[8] - q);
    // a - q - ошибка компиляции:
    // нельзя вычитать int* и char*
    return 0;
}
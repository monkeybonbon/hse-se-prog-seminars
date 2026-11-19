#include <stdio.h>

int main(void) {
    int i = 42, a = 100;

    printf("%ld\n", i++ + 15L);
    printf("%d\n", ++i + 015);

    a = i += i;
    printf("%d\n", a);

    printf("%d\n", a > 0 ? ++i : i++);

    return 0;
} 

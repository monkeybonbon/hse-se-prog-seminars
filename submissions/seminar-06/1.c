#include <stdio.h>

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main()
{
    int x = 3, y = 7;
    update(&x, &y);
    
    printf("%i %i\n", x, y); // x = 10, y = 3
    
    x = 3;
    update(&x, &x);

    printf("%i\n", x); // x = 0
}


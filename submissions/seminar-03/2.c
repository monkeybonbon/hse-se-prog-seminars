#include <stdio.h>

int main(void)
{
    int i = 42, a = 100;
    printf("%li\n", i++ + 15L); // тут тип long int
    printf("%i %i\n\n", a, i);


    i = 42; a = 100;
    printf("%i\n", ++i + 015); // 015_8 = 13_10
    printf("%i %i\n\n", a, i); // int
    
    i = 42; a = 100;
    a = i += i; // сначала i = 84, затем a = 84
    printf("%i %i\n", a, i); // int

    i = 42; a = 100;
    a > 0 ? ++i : i++; // не будет разницы между ++i и i++
    printf("%i %i\n", a, i); // int

    return 0;
}
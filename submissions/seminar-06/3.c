#include <stdio.h>

int mystery(int n) {
    if (n <= 1)
        return 1;

    int a = mystery(n - 1);
    return a + n;
}

/*
1. произойдет 4 вызова 
2. глубина рекурсии 4
3. значения а при 
n = 4 ; 6
n = 3 ; 3
n = 2 ; 1

4. самый первый вызов вернет 10



*/
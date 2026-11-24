#include <stdio.h>

int mystery(int n) {
    if (n <= 1)
        return 1;

    int a = mystery(n - 1);
    return a + n;
}

int main(void) {
    printf("%d\n", mystery(4));
    return 0;
}
/*
 1. Всего вызовов: 4
 2. Максимальная глубина рекурсии: 4
 3. в mystery(1) a нема, в mystery(2) a = 1, в mystery(3) a = 3, в mystery(4) a = 6
 4. 10
 */
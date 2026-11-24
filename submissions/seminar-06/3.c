#include <stdio.h>

int main(void) {
    printf("A%d", 10);
}
// 1) 4 вызова
// 2) макс глубина = 4
// 3) mystery(2): a = 1, return = 3
// mystery(3): a = 3, return = 6
// mystery(5): a = 6, return = 10
// 4) 10

#include <stdio.h>

int main() {
    int i, a;
    i = 42; a = 100;
    printf("%ld | i = %d\n", i++ + 15L, i);
    printf("%d | i = %d\n", ++i + 015, i);
    printf("%d | i = %d, a = %d\n", a = i += i, i, a);
    printf("%d | i = %d\n", a > 0 ? ++i : i++, i);
    return 0;
}

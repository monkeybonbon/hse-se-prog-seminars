#include <stdio.h>

int main(void) {
    int i = 42, a = 100;

    long x = i++ + 15L;
    printf("%ld long i=%d\n", x, i);

    i = 42;
    int y = ++i + 015;
    printf("%d int i=%d\n", y, i);

    i = 42;
    a = 100;
    int z = (a = i += i);
    printf("%d int i=%d a=%d\n", z, i, a);

    i = 42;
    a = 100;
    int k = a > 0 ? ++i : i++;
    printf("%d int i=%d a=%d\n", k, i, a);

    return 0;
}

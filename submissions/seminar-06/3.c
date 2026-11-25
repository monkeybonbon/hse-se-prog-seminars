#include <stdio.h>

int mystery(int n) {
    if (n <= 1) {
        return 1;
    }

    int a = mystery(n - 1);
    return a + n;
}

int main(void) {
    printf("Number of calls: 4\n");
    printf("Maximum recursion depth: 4\n");
    printf("a values: 1, 3, 6\n");
    printf("Result: %d\n", mystery(4));

    return 0;
}

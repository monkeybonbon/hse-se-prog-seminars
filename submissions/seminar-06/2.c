#include <stdio.h>

void process(int n) {
    if (n <= 0) {
        return;
    }

    printf("A%d ", n);
    process(n - 2);
    printf("B%d ", n);
}

int main(void) {
    process(5);
    printf("\n");
    return 0;
}

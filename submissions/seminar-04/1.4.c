#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    unsigned char *ptr = (unsigned char *)&a;

    for (int i = 0; i < 4; ++i) {
        printf("%02x ", *(ptr + 3 - i));
    }
    printf("\n");

    return 0;
}

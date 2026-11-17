#include <stdio.h>
#include <stddef.h>

int main() {
	char c[9];
	int a[] = { 1, 2, 3, 4, 5 };
	int* p = &a[1], i = 3;
	char* q = c;

	printf("Выполнение выражений\n");

    printf("a) sizeof(c) = %zu\n", sizeof(c));
    printf("б) sizeof(a) = %zu\n", sizeof(a));
    printf("в) sizeof(p) = %zu\n", sizeof(p));
    printf("г) sizeof(q) = %zu\n", sizeof(q));
    printf("д) sizeof(*p) = %zu\n", sizeof(*p));
    printf("е) sizeof(*q) = %zu\n", sizeof(*q));

    return 0;
}
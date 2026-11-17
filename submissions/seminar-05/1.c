#include <stdio.h>
#include <stddef.h>

int main() {
	char c[9];
	int a[] = { 1, 2, 3, 4, 5 };
	int* p = &a[1], i = 3;
	char* q = c;

	printf("Выполнение выражений\n");

	int res1 = i++;
	printf("1. i++ Значение: %d, Тип: int, Побочный эффект: i = %d\n", res1, i);

	int res2 = ++i;
	printf("2. ++i Значение: %d, Тип: int, Побочный эффект: i = %d\n", res2, i);

	int safe_index = i - 1;
	int res3 = a[safe_index]--;
	printf("3. a[i]-- Значение: %d, Тип: int, Побочный эффект: a[%d] = %d, i остался = %d\n", res3, safe_index, a[safe_index], i);

	int res4 = *p++;
	printf("4. *p++ Значение: %d, Тип: int, Побочный эффект: p указывает на a[2]\n", res4);

	int res5 = ++ * p;
	printf("5. ++*p Значение: %d, Тип: int, Побочный эффект: a[2] = %d\n", res5, a[2]);

	int res6 = *++p;
	printf("6. *++p Значение: %d, Тип: int, Побочный эффект: p указывает на a[3]\n", res6);

	ptrdiff_t res7 = p - a;
	printf("7. p - a Значение: %td, Тип: ptrdff_t, Побочный эффект: нет\n", res7);

	ptrdiff_t res8 = &c[8] - q;
	printf("8. &c[8] - q Значение: %td, Тип : ptrdiff_t, Побочный эффект : нет\n", res8);

	printf("9. a - q ОШИБКА КОМПИЛЯЦИИ: нельзя вычитать указатели разных типов (int* и char*)\n");

	return 0;
}
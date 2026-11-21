#include <stdio.h>

int main(void) {
	int a = 2;
	int* p = &a;
	int* q = &(*p);
	(*q)++;
	
	printf("%p %p %d", p, q, a);
	
	return 0;
}

// Вывод: <адрес_a> <адрес_a> 3 (если подключен <stdio.h>, иначе ошибка компиляции).
// p и q указывают на a, (*q)++ меняет a с 2 на 3.
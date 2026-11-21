/*
1.1 - а, в, г, и, л, м, о
1.2 - адрес а, адрес а, а + 1 = 3
*/


// 1.3
/*
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	
	int* a_ptr = &a;
	int* b_ptr = &b;
	
    int tmp = *b_ptr;
    *b_ptr = *a_ptr;
    *a_ptr = tmp;

	// Ваш код. Использовать только a_ptr, b_ptr
	// (можно создавать другие переменные)
	
	printf("%d %d\n", a, b);
	return 0;
}
*/

// 1.4

// #include <stdio.h>

// int main(void)
// {
//     int n;
//     scanf("%i", &n);

// 	for (int i = (int)sizeof(n) - 1; i >= 0; i--)
// 	{
// 		printf("%02x ", (unsigned int)* ((unsigned char *)&n + i));
// 	}

// 	printf("\n");
	
//     return 0;
// }
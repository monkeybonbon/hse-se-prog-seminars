#include <stdio.h>

int main()
{
	printf("%d \n", 17);
	int a[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	//printf("%d", a);
	int *p = &a[5];
	p = p-5;
	for (int i = 0; i < 16; i++)
	{
		*(p + i) = 0;
	}
	//for (int i = 0; i < 16; i++)
	//{
	//	printf("%d \n", a[i]);
	//}
	return 0;
}
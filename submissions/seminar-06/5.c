#include <stdio.h>


unsigned digit_sum(unsigned n)
{
	
	if (n <= 0)
	{
		return 0;
	}
	

	unsigned res = digit_sum(n / 10);
	
	return res + (n%10);

}
int main()
{
	int n = 12345;
    int result = digit_sum(n);
	printf("%d", result);
}
#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b);

int main()
{
	unsigned int a = 2;
	unsigned int b = 3;
	unsigned int res;

	res = lcm(a, b);

	printf("%d\n", res);
	return (0);
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int do_op(int num1, int num2, char op)
{
	if (op == '+')
		return (num1 + num2);
	else if (op == '-')
		return (num1 - num2);
	else if (op == '*')
		return (num1 * num2);
	else if (op == '/')
		return (num1 / num2);
	else if (op == '%')
		return (num1 % num2);
	return (0);
}

int main(int ac, char **av)
{
	int res;

	res = 0;
	if (ac == 4)
	{
		res = do_op(atoi(av[1]), atoi(av[3]), av[2][0]);
		printf("%i", res);
	}
	printf("\n");
	return (0);
}

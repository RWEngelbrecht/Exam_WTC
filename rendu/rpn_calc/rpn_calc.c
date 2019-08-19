/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:25:45 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/19 12:54:19 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		do_op(int n1, int n2, int op)
{
	if (op == '+')
		return (n1 + n2);
	else if (op == '-')
		return (n1 - n2);
	else if (op == '*')
		return (n1 * n2);
	else if (op == '/')
		return (n1 / n2);
	else if (op == '%')
		return (n1 % n2);
	return (0);
}

void	rpn_solve(int *args)
{
	int i;
	int val1;
	int val2;
	int op;

	i = 0;
	val1 = 0;
	while (!(args[i] == '+' && args[i]  == '-' && args[i] == '*'
				&& args[i] == '/' && args[i] == '%'))
	{
		i++;
		if (args[i] == '+' || args[i]  == '-' || args[i] == '*'
				|| args[i] == '/' || args[i] == '%')
		{
			op = args[i];
			if (!val1)
				do_op(args[i - 2], args[i - 1], args[i]);
			//carry on here
		}
	}
}

int main(int ac, char **av)
{
	int *args;
	int i;
	int j;

	args = NULL;
	i = 0;
	j = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= '0' && av[1][i] <= '9')
			{
				args[j] = atoi(av[1][i]);
				j++;
			}
			else if (av[1][i] == '+' || av[1][i]  == '-' || av[1][i] == '*'
						|| av[1][i] == '/' || av[1][i] == '%')
			{
				args[j] = av[1][i];
				j++;
			}
			i++;
		}
		rpn_solve(args);
	}
	else
		write(1, "Error\n", 6);
}

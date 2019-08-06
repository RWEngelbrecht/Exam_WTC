/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:17:19 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/06 10:59:02 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int n)
{
	int i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int		curr;
	int		arg;
	int		tmp;
	int		i;


	curr = 2;
	arg = 0;
	tmp = 0;
	i = 0;
	if (ac == 2)
	{
		arg = atoi(av[1]);
		tmp = arg;
		while (!is_prime(tmp))
		{
			if (tmp % curr == 0 && is_prime(curr))
			{
				tmp /= curr;
				printf("%i*", curr);
			}
			else
				curr++;
		}
		printf("%i", tmp);
	}
	printf("\n");
	return (0);
}

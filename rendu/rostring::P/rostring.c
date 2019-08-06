/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:44:46 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/06 13:25:39 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac > 1)
	{
		while (av[1][j] == ' ' || av[1][j] == '\t')
		{
			j++;
			i++;
		}
		while (av[1][j] >= 33 && av[1][j] <= 126)
			j++;
		while (av[1][j])
		{
			while (av[1][j] == ' ' || av[1][j] == '\t')
				j++;
			while (av[1][j] >= 33 && av[1][j] <= 126)
			{
				write(1, &av[1][j], 1);
				j++;
			}
			if (av[1][j - 1] != ' ' && av[1][j - 1] != '\t')
				write(1, " ", 1);
		}
		while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brianfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:14:29 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/06 11:32:08 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	char *str;
	int i;
	int tab[4096];
	int *ptr;
	int loop;

	ptr = tab;
	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str[i])
		{
			if (str[i] == '>')
				ptr++;
			else if (str[i] == '<')
				ptr--;
			else if (str[i] == '+')
				++(*ptr);
			else if (str[i] == '-')
				--(*ptr);
			else if (str[i] == '.')
				write(1, ptr, 1);
			else if (str[i] == '[' && *ptr == 0)
			{
				loop = 1;
				while (loop != 0)
				{
					i++;
					if (str[i] == '[')
						loop++;
					if (str[i] == ']')
						loop--;
				}
			}
			else if (str[i] == ']' && *ptr != 0)
			{
				loop = 1;
				while (loop != 0)
				{
					i--;
					if (str[i] == ']')
						loop++;
					if (str[i] == '[')
						loop--;
				}
			}
			i++;
		}
	}
	return (0);
}

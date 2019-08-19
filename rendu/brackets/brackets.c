/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:05:19 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/19 08:29:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int brackets_closed(char *s, char c, int i, int b)
{
	while (b && *(++s) && i++)
	{
		if (*s == c || *s == c  + c % 2 + 1)
		{
			if (*s == c)
				++b;
			else
				--b;
		}
	}
	return (i);
}

int		brackets(char *s, char c)
{
	if (*s == c)
		return (1);
	else if (!*s || *s == ']' || *s == '}' || *s == ')')
		return (0);
	else if (*s == '[' || *s == '{' || *s == '(')
		return (brackets(s + 1, *s + *s % 2 + 1)
				* brackets(s + brackets_closed(s, *s, 1, 1), c));
	else
		return (brackets(s + 1, c));
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac >= 2)
	{
		while (++i < ac)
		{
			if (brackets(av[i], 0))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

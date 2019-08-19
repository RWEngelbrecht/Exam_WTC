/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 09:54:02 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/19 10:48:52 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pal(char *str, int start, int end)
{
	while (start <= end)
	{
		write(1, &str[start++], 1);
	}
}

void	biggest_pal(char *str)
{
	int i;
	int len;
	int start;
	int end;
	int biggest_len;
	int hold;


	len = 0;
	while (str[len])
		len++;
	if (len == 1)				//SINGLE LETTERS ARE PALINDROMES!!!
		write(1, str, 1);
	i = 1;
	biggest_len = 1;
	while (++i < len)
	{
		start = i - 1;
		end = i;
		while (start >= 0 && end < len && str[start] == str[end])
		{
			if (end - start + 1 >= biggest_len)
			{
				hold = start;
				biggest_len = end - start + 1;
			}
			--start;
			++end;
		}
		start = i - 1;
		end = i + 1;
		while (start >= 0 && end < len && str[start] == str[end])
		{
			if (end - start + 1 >= biggest_len)
			{
				hold = start;
				biggest_len = end - start + 1;
			}
			--start;
			++end;
		}
	}
	print_pal(str, hold, hold + biggest_len - 1);

}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		biggest_pal(av[1]);
	}
	write(1, "\n", 1);
}

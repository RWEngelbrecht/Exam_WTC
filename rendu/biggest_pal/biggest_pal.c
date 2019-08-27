/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:52:26 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/27 11:33:00 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pal(char *s, int start, int len)
{
	while (start <= len)
	{
		write(1, &s[start], 1);
		start++;
	}
}

void	biggest_pal(char *s)
{
	int i;
	int len;
	int big_len;
	int start;
	int end;
	int hold;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	big_len = 1;
	hold = 0;
	while (++i < len)
	{
		start = i - 1;
		end = i;
		while (start >= 0 && end < len && s[start] == s[end])
		{
			if (end - start + 1 >= big_len)
			{
				hold = start;
				big_len = end - start + 1;
			}
			--start;
			++end;
		}
		start = i - 1;
		end = i + 1;
		while (start >= 0 && end < len && s[start] == s[end])
		{
			if (end - start + 1 >= big_len)
			{
				hold = start;
				big_len = end - start + 1;
			}
			--start;
			++end;
		}	
	}
	print_pal(s, hold, hold + big_len - 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		biggest_pal(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}

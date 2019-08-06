/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 07:38:16 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/24 07:44:08 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i;

	i = 128;
	while (octet >= 0 && i)
	{
		if (octet >= i)
		{
			write(1, "1", 1);
			octet %= i;
			i /= 2;
		}
		else
		{
			write(1, "0", 1);
			i /= 2;
		}
	}
}

int main()
{
	unsigned char c = 't';

	print_bits(c);
	write(1, "\n", 1);
	return (0);
}

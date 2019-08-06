/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 07:45:24 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/24 08:11:44 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char r;
	int			len;

	r = 0;
	len = 8;
	while(len)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
		len--;
	}
	return (r);
}

int main()
{
	unsigned char c = 't';
	unsigned char r = reverse_bits(c);

	printf("c = %c\nr = %c\n", c, r);
	return (0);
}

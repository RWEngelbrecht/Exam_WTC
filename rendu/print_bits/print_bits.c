/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:18:41 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/02 13:32:56 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int oct;
	int div;

	div = 128;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct)
		{
			write(1, "1", 1);
			oct %= div;
		}
		else
			write(1, "0", 1);
		div /= 2;
	}
}

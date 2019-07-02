/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:52:31 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/02 14:40:49 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int an;
	unsigned int bn;
	unsigned int res;

	an = 0;
	bn = 0;
	res = 0;
	if (!a || !b)
		return (0);
	an = 1;
	bn = 1;
	while (res != 1)
	{
		res = a / an;
		an++;
	}
	res = 0;
	while (res != 1)
	{
		res = b / bn;
		bn++;
	}
	return (an * bn);
}

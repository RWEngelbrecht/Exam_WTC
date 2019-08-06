/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:35:41 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/05 11:33:14 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char *base_str = "0123456789ABCDEF";
	char *ret;
	long num;
	int len;

	len = 0;
	if (value == 0)
		return ("0");
	if (value == 2147483647 && base == 10)
		return ("2147483647");
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	num = value;
	while (num)
	{
		len++;
		num /= base;
	}
	num = value;
	if (value < 0)
	{
		if (base == 10)
			len++;
		num *= -1;
	}
	ret = (char*)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	while (num)
	{
		ret[--len] = base_str[num % base];
		num /= base;
	}
	if (value < 0 && base == 10)
		ret[0] = '-';
	return (ret);
}
#include <stdio.h>
int main(int ac, char **av)
{
	int n = 0;
	int base = 0;

	if (ac == 3)
	{
		n = atoi(av[1]);
		base = atoi(av[2]);
	}
	printf("n = %s\n", ft_itoa_base(n, base));
	return (0);
}

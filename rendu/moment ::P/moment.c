/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 06:59:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/06 08:04:40 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa(unsigned int num)
{
	int len;
	unsigned int tmp;
	char *ret;

	len = 1;
	tmp = num;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	ret = (char *)malloc(sizeof(char) * len);
	ret[--len] = '\0';
	while (num)
	{
		ret[--len] = num % 10 + '0';
		num /= 10;
	}
	return (ret);
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char *moment(unsigned int duration)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 258);
	if (duration >= 0 && duration < 60)						//seconds
	{
		if (duration == 1)
			str = ft_strjoin("1", " second ago.");
		else if (duration == 0)
			str = ft_strjoin("0", " seconds ago.");
		else
			str = ft_strjoin(ft_itoa(duration), " seconds ago.");
	}
	else if (duration >= 60 && duration < 3600)				//minutes
	{
		if ((duration / 60) == 1)
			str = ft_strjoin("1", " minute ago.");
		else
		{
			duration /= 60;
			str = ft_strjoin(ft_itoa(duration), " minutes ago.");
		}
	}
	else if (duration >= 3600 && duration < 86400)
	{
		if ((duration / 3600) == 1)
			str = ft_strjoin("1", " hour ago.");
		else
		{
			duration /= 3600;
			str = ft_strjoin(ft_itoa(duration), " hours ago.");
		}
	}
	else if (duration >= 86400 && duration < 2592000)
	{
		if ((duration / 86400) == 1)
			str = ft_strjoin("1", " day ago.");
		else
		{
			duration /= 86400;
			str = ft_strjoin(ft_itoa(duration), " days ago.");
		}
	}
	else if (duration >= 2592000)
	{
		if ((duration / 2592000) == 1)
			str = ft_strjoin("1", " month ago.");
		else
		{
			duration /= 2592000;
			str = ft_strjoin(ft_itoa(duration), " months ago.");
		}
	}
	return (str);
}

#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int	len1;
	int	len2;
	int 	i;
	char	*str;

	len1 = 0;
	len2 = 0;
	i = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = (char*)malloc(sizeof(char) * (len1 + len2) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++; 
	}
	i = 0;
	while (s2[i])
	{
		str[len1 + i] = s2[i];
		i++;
	}
	str[len1 + i] = '\0';
	return (str);
}

char *ft_itoa(int nbr)
{
	char *str;
	char *min;

	str = (char*)malloc(sizeof(char) * 2);
	if (nbr <= -2147483648)
	{
		min = "-2147483648";
		return (min);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-nbr));
	}
	else if (nbr > 9)
		str = ft_strjoin(ft_itoa(nbr / 10), ft_itoa(nbr % 10));
	else
	{
		str[0] = nbr + '0';
		str[1] = '\0';
	}
	return (str);
}
#include <stdio.h>
int main()
{
	printf("%s\n", ft_itoa(8));
	return (0);
}

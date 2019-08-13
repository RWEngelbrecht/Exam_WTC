int	ft_atoi(const char *str)
{
	int res;
	int neg;

	res = 0;
	neg = 1;
	while (*str)
	{
		if (*str == '-')
			neg = -1;
		if (*str >= '0' && *str <= '9')
			res = 10 * res + (*str - '0');
		str++;
	}
	if (neg < 0)
		return (res * neg);
	return (res);

}

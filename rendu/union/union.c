#include <unistd.h>

int has_char(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

void	ft_union(char *av, char *uni, int *pos)
{
	while (*av)
	{
		if (has_char(uni, *av) == 0)
		{
			write(1, &(*av), 1);
			uni[*pos] = *av;
			(*pos)++;
		}
		av++;
	}
}

int main(int ac, char **av)
{
	int pos;
	char uni[1024];

	if (ac == 3)
	{
		pos = 0;
		ft_union(av[1], uni, &pos);
		ft_union(av[2], uni, & pos);
	}
	write(1, "\n", 1);
	return (0);
}

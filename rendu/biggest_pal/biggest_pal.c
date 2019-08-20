#include <unistd.h>

void print_pal(char *s, int start, int end)
{
	while (start <= end)
		write(1, &s[start++], 1);
}

void biggest_pal(char *s)
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
	if (len == 1)
		write(1, &s[i], 1);
	big_len = 1;
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
}

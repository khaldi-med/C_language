#include <unistd.h>

int	ft_atoi(char *s)
{
	int	n;

	n = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (n);
}

void	ft_to_hex(int n)
{
	char	*s;
	char	c;

	s = "0123456789abcdef";
	c = 0;
	if (n >= 16)
		ft_to_hex(n / 16);
	c = s[n % 16];
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	n = ft_atoi(av[1]);
	ft_to_hex(n);
	write(1, "\n", 1);
}

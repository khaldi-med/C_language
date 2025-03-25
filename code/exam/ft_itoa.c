#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	tmp;

	len = n <= 0 ? 2 : 1;
	tmp = n;
	while (tmp && ++len)
		tmp /= 10;
	if (!(s = malloc(sizeof(char *) * len)))
		return (NULL);
	s[--len] = '\0';
	if (n <= 0)
		s[0] = n < 0 ? '-' : '0';
	while (n)
	{
		s[--len] = (n < 0 ? -n : n) % 10 + '0';
		n /= 10;
	}
	return (s);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));
	}
	write(1, "\n", 1);
	return (0);
}

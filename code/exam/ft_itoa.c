#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	tmp;

	if (n == -2147483648)
	{
		return ("-2147483648");
	}
	i = 0;
	tmp = n;
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	if (!(s = malloc(sizeof(char *) * i + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[i] = '\0';
	while (n)
	{
		s[--i] = n % 10 + '0';
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

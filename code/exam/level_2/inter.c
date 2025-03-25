#include <unistd.h>

int	main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	char	seen[256] = {0};
	char	printed[256] = {0};
	int		i;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	s1 = av[1];
	s2 = av[2];
	while (s2[i])
	{
		seen[(unsigned char)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (seen[(unsigned char)s1[i]] && !printed[(unsigned char)s1[i]])
		{
			write(1, &s1[i], 1);
			printed[(unsigned char)s1[i]] = 1;
		}
		i++;
	}
	write(1, "\n", 1);
}

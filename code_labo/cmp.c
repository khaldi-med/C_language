#include <stdio.h>

int	ft_strcmp(char *s, char *t)
{
	for (; *s == *t; ++s, ++t)
	{
		if (*s == '\0')
			return (0);
	}
	return (*s - *t);
}

int	main(int argc, char **av)
{
	(void)argc;
	printf("%d\n", ft_strcmp(av[1], av[2]));
	return (0);
}

#include "headr.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d", ft_strcmp(av[1], av[2]));
	}
	return (0);
}

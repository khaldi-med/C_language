#include "headr.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_strrev(av[1]);
		printf("%s", av[1]);
	}
	return (0);
}

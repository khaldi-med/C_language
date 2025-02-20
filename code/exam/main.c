#include "headr.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		fizzbuzz(ft_itoa(av[1]));
	}
	return (0);
}

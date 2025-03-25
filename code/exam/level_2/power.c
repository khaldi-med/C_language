#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n / 2)
	{
		if (n % 2 == 0)
			n /= 2;
	}
	return (n == 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", is_power_of_2(atoi(av[1])));
	return (0);
}

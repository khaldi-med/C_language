#include <stdio.h>
#include <stdlib.h>

void	fprime(unsigned int n)
{
	unsigned int	i;

	i = 2;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	else if (n < 1)
		return ;
	while (i <= n)
	{
		if (n % i == 0)
		{
			printf("%i", i);
			n /= i;
			i = 1;
			if (n == 1)
				return ;
			else
				printf("*");
		}
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	fprime(atoi(av[1]));
}

// great commen divisor

#include <stdio.h>
#include <stdlib.h>

int	gcd(int a, int b)
{
	int	tmp;

	tmp = 0;
	while (a > 0)
	{
		if (a < b)
		{
			tmp = a;
			a = b;
			b = tmp;
		};
		a = a - b;
	}
	return (b);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;

	a = atoi(av[1]);
	b = atoi(av[2]);
	if (!av[1] || !av[2] || !av[1][0] || !av[2][0])
		return (0);
	if (ac == 3)
	{
		if (a > 0 && b > 0)
			printf("The great common divisor for %d and %d is: %d\n", a, b,
					gcd(a, b));
		else
			printf("the number must be grat than 0!\n");
	}
	else
		printf("The argemments not valid!");
	return (0);
}

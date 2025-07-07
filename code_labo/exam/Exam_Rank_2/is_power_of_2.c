#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (i < n && i < 2147483648)
		i *= 2;
	return (n == i);
}

int	main(void)
{
	printf("%d\n", is_power_of_2(9));
	return (0);
}

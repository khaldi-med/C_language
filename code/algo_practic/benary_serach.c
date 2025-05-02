#include <stdio.h>
#include <stdlib.h>

int	beanry_search(char *s, int target)
{
	int	max;
	int	min;
	int	i;

	max = strlen(s);
	min = 0;
	i = max / 2;
	while (s[i])
	{
		if (s[min] != target)
			min += 1;
		if (min > max)
			return (-1);
		if (target == s[i])
			return (target);
	}
}

int	main(int ac, char **av)
{
}

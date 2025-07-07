#include <stdio.h>
#include <stdlib.h>

int	abc(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	*arr;
	int	size;

	size = abc(end - start) + 1;
	i = 1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	if (size == 1)
		arr[0] = start;
	if (start < end)
	{
		while (i < size)
		{
			arr[i] = start + i;
			i++;
		}
	}
	else if (start > end)
	{
		while (i < size)
		{
			arr[i] = start - i;
			i++;
		}
	}
	return (arr);
}

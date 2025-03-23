// #include <stdio.h>
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

	size = abc(start - end) + 1;
	i = 1;
	arr = malloc(sizeof(int) * 1024);
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

// int	main(void)
// {
// 	int	*tab;
// 	int	i;
// 	int	start;
// 	int	end;
// 	int	size;
//
// 	start = 0;
// 	end = -3;
// 	size = abc(end - start) + 1;
// 	i = 0;
// 	tab = ft_range(start, end);
// 	while (i < size)
// 	{
// 		printf("%i, ", tab[i]);
// 		i++;
// 	}
// }

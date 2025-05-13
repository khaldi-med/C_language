#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 63;
	printf("after => a is: %d b is: %d\n", a, b);
	ft_swap(&a, &b);
	printf("befor => a is: %d b is: %d\n", a, b);
	return (0);
}

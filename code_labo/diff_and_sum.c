#include <stdio.h>

int	sum_and_diff(int a, int b, int *res)
{
	int	sum;

	sum = a + b;
	*res = a - b;
	return (sum);
}

int	main(void)
{
	int	b;
	int	diff;

	b = 2;
	printf("The sum of 5 and %d is %d\n", b, sum_and_diff(5, b, &diff));
	printf("The difference of 5 and %d is %d\n", b, diff);
	return (0);
}

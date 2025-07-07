/* ************************************************************************** */
/*   codewars.com                                                             */
/*   sum_sp.c                                                                 */
/*                                                                            */
/*   Created: 2025/01/22 13:36:54                                             */
/*   Updated: 2025/01/22 13:36:54                                             */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	sum_of_squares(unsigned int number)
{
	unsigned int	sum;
	unsigned int	i;

	sum = 0;
	i = 1;
	while (i <= number)
	{
		sum += i * i;
		i++;
	}
	return (sum);
}

unsigned int	square_of_sum(unsigned int number)
{
	unsigned int	sum;
	unsigned int	i;

	sum = 0;
	i = 1;
	while (i <= number)
	{
		sum += i;
		i++;
	}
	return (sum * sum);
}

unsigned int	difference_of_squares(unsigned int number)
{
	return (square_of_sum(number) - sum_of_squares(number));
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("diff: %d\n", difference_of_squares(atoi(av[1])));
		printf("sum_of_sq: %d\n", sum_of_squares(atoi(av[1])));
		printf("sq_of_sum: %d\n", square_of_sum(atoi(av[1])));
	}
	return (0);
}

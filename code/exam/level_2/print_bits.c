#include <unistd.h>

void	print_bits(unsigned char c)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = ((c >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

int	main(void)
{
	print_bits(8);
	write(1, "\n", 1);
	return (0);
}

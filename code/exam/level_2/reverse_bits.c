#include <stdio.h>

unsigned char	reverse_bits(unsigned char c)
{
	unsigned int	i;
	char			bit;

	i = 0;
	bit = 0;
	while (i <= 7)
	{
		if ((c >> i) & 1)
			bit |= 1;
		bit <<= 1;
		i++;
	}
	return (bit);
}

int	main(void)
{
	printf("%d\n", reverse_bits('A'));
	return (0);
}

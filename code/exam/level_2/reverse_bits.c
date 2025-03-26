#include <stdio.h>

unsigned char	reverse_bits_2(unsigned char octet)
{
	int				i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = c * 2 + (octet % 2);
		octet /= 2;
		i++;
	}
	return (c);
}

int	main(void)
{
	printf("%d\n", reverse_bits_2('A'));
	return (0);
}

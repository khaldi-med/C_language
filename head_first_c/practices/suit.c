#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char *av)
{
	char	suit;

	suit = 'H';
	switch (suit)
	{
	case 'C':
		puts("Clubs");
		break ;
	case 'D':
		puts("Diamonds");
		break ;
	case 'H':
		puts("Hearts");
		break ;
	default:
		puts("Spades");
	}
}

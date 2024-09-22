#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	card_name[3];
	int		count;
	int		val;

	count = 0;
	while (card_name[0] != "X")
	{
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		val = 0;
		switch (card_name[0])
		{
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break ;
		case 'A':
			val = 11;
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10))
			{
				puts("I don't understand that value!");
				continue ;
			}
		}
		if ((val > 2) && (val < 7))
		{
			count++;
		}
		else if (val == 10)
		{
			count--;
		}
		printf("Current count: %i\n", count);
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	ex[20];

	puts("Enter boyfriend's name: ");
	scanf("%19s", ex);
	printf("Dear %s.\n\n\tYou're history.\n", ex);
}

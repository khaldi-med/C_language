#include <stdio.h>
#include <stdlib.h>

void	derections(int *lat, int *lon)
{
	*lat -= 1;
	*lon += 1;
}

int	main(void)
{
	int	latutied;
	int	longtutied;

	latutied = 32;
	longtutied = -64;
	derections(&latutied, &longtutied);
	printf("Wraning, it's in: [%i, %i]\n", latutied, longtutied);
}

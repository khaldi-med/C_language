#include <stdio.h>

int	main(void)
{
	int		intval;
	void	*vptr;

	intval = 255958283;
	vptr = &intval;
	printf("The value at vptr as an int is %d\n", *((int *)vptr));
	printf("The value at vptr as a char is %d\n", *((char *)vptr));
	return (0);
}

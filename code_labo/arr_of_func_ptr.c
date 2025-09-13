/*
Array of function pointers
Function pointers are commonly used in programs where a user can select a
function to be carried out from a list of options. Using an array of function
pointers to all possible functions, the user’s choice can be translated into an
index that allows to select the correct function pointer from the array. This
is illustrated in the next example:
*/

#include <stdio.h>

int	add(int, int);
int	subtract(int, int);
int	main(void)
{
	int	(*fptr[2])(int, int);

	int a, choice;
	(fptr[2])(int, int) = {add, subtract};
	printf("Enter your choice:\n");
	printf("\t0:\taddition (10 + 2)\n\t1:\tsubtraction (10 - 2)\n");
	scanf("%d%*c", &choice);
	a = (*fptr[choice])(10, 2);
	printf("The requested operation gives: %d\n", a);
	return (0);
}
int	add(int x, int y)
{
	return (x + y);
}
int	subtract(int x, int y)
{
	return (x - y);
}

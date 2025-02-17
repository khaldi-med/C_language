#include <stdio.h>

int main (void)
{
	const int limit = 10;
	const int * limitp = &limit;
	int i=27;
	limitp = &i;
	//int val;
	//char string[10] = "250";
	//sscanf (string, "%d", &val);
	printf ("The value in the string is %d\n", *limitp);
	return 0;
}



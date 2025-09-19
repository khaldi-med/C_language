#include <stdio.h>
#include <stdlib.h>
#define FILENAME "example.txt"

int	main(void)
{
	FILE	*pFile;

	pFile = fopen(FILENAME, "w");
	if (pFile == NULL)
	{
		printf("The file %s cannot be opened.", FILENAME);
		exit(1);
	}
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);
	fclose(pFile);
	return (0);
}

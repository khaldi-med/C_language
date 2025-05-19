#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	buff[100];

	if (read(0, buff, 100) == -1)
	{
		perror("read error");
		exit(1);
	}
	printf("%s\n", buff);
	return (0);
}

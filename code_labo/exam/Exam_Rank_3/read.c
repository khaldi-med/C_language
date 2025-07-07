#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	buff[100];
	int		fd;

	fd = open("text.c", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		perror("open:");
	if (read(fd, buff, 100) == -1)
	{
		perror("read:");
		exit(1);
	}
	printf("%s", buff);
	return (0);
}

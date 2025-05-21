#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_error(char *s)
{
	perror(s);
	exit(1);
}

int	main(int argc, char **argv)
{
	char	s[1048];
	char	*str;
	ssize_t	read_bytes;

	if (argc != 2)
		ft_error("Error: program requires exactly one argument");
	str = argv[1];
	while (1)
	{
		// Read input from stdin (file descriptor 0)
		read_bytes = read(0, s, 1047); // Leave space for null terminator
		if (read_bytes == -1)
			ft_error("read error");
		// Properly null-terminate the string
		if (read_bytes < 1048)
			s[read_bytes] = '\0';
		else
			s[1047] = '\0'; // Ensure null-termination if buffer is full
		// Remove trailing newline if present
		if (read_bytes > 0 && s[read_bytes - 1] == '\n')
			s[read_bytes - 1] = '\0';
		if (strcmp(str, s) == 0)
		{
			write(1, "identical\n", 10);
			exit(0);
		}
		else
			printf("try again :)\n");
	}
	return (0);
}

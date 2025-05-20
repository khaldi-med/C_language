// #include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_error(char *s)
{
	perror(s);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*s;
	char	*str;

	str = argv[1];
	s = malloc(1048);
	if (argc < 2)
		ft_error("arg error");
	while (1)
	{
		if (read(0, s, 1048) == -1)
			ft_error("read error");
		if (strcmp(str, s) == 0)
		{
			write(1, "indenticle\n", 11);
			return (0);
		}
		else
			printf("try agin ):");
	}
	return (0);
}

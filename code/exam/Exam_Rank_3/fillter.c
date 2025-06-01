// #include <cmath>
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
	int		read_bits;
	int		i;

	read_bits = 0;
	str = argv[1];
	if (argc != 2)
		ft_error("arg error not");
	while (1)
	{
		read_bits = read(0, s, 1047);
		if (read_bits == -1)
			ft_error("read error");
		if (read_bits < 1048)
			s[read_bits] = '\0';
		else
			s[1047] = '\0';
		if (read_bits > 0 && s[read_bits - 1] == '\n')
			s[read_bits - 1] = '\0';
		if (strcmp(str, s) == 0)
		{
			write(1, "identical\n", 10);
			i = 0;
			while (s[i])
			{
				s[i] = '*';
				write(0, &s[i], 1);
				i++;
			}
			write(1, "\n", 1);
			exit(0);
		}
		else
			printf("try agin ):\n");
	}
	return (0);
}

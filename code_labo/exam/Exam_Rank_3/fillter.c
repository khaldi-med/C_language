// #include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_error(char *s)
{
	perror(s);
	exit(1);
}

int	ft_strch(char *str, char *target)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str || !target)
		return (0);
	while (str[i])
	{
		if (str[i] == target[j])
		{
			i++;
			j++;
		}
		else
			i++;
		if (target[j] == '\0')
			break ;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	buff[2048];
	int		readline;
	int		i;

	(void)argv;
	readline = 0;
	if (argc != 0)
	{
		if ((readline = read(1, buff, 2048) == -1))
			ft_error("read Error!");
		else if (readline != 0)
			buff[readline] = '\0';
		i = 0;
		while (buff[i] != '\0')
		{
			if (ft_strch(buff, argv[1]))
			{
				printf("there are indticatle");
				exit(0);
			}
			else
			{
				printf("there are not :(\n");
				exit(1);
			}
			i++;
		}
	}
	return (0);
}

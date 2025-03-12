#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	int		space;

	space = -1;
	i = 0;
	str = av[1];
	if (ac == 2)
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '\t')
			{
				if (space == 1)
					write(1, " ", 1);
				space = 0;
				write(1, &str[i], 1);
			}
			else if (space == 0)
				space = 1;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

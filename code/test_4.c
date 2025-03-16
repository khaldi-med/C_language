#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		write(1, " ", 1);
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
			write(1, &av[1][i++], 1);
		if (av[1][i])
		{
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			if (av[1][i])
				write(1, " ", 1);
			else
				break ;
		}
	}
	write(1, "\n", 1);
}

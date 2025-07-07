#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	start = 0;
	end = 0;
	while (av[1][i])
	{
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		start = i;
		while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
			i++;
		end = i;
		if (av[1][i])
		{
			while (av[1][i])
			{
				while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
					i++;
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
					write(1, &av[1][i++], 1);
				write(1, " ", 1);
			}
		}
		else
			break ;
	}
	while (start < end)
		write(1, &av[1][start++], 1);
	write(1, "\n", 1);
}

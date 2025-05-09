#include <unistd.h>

void	manychar(char c, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		write(1, &c, 1);
		i++;
	}
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	*dw;
	char	*up;
	int		j;

	j = 0;
	i = 0;
	dw = "abcdefghijklmnopqrstuvwxyz";
	up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (ac == 2)
	{
		while (av[1][i])
		{
			j = 0;
			if (is_upper(av[1][i]))
			{
				while (up[j])
				{
					if (av[1][i] == up[j])
					{
						manychar(av[1][i], j);
						break ;
					}
					j++;
				}
			}
			else if (is_lower(av[1][i]))
			{
				while (dw[j])
				{
					if (av[1][i] == dw[j])
					{
						manychar(av[1][i], j);
						break ;
					}
					j++;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

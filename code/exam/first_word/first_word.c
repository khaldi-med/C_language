#include <unistd.h>

int	main(int ac, char **av)
{
	char	*s;
	int		i;

	s = av[1];
	i = 0;
	if (ac == 2)
	{
		while (s[i])
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
				i++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				write(1, &s[i++], 1);
			break ;
		}
	}
	write(1, "\n", 1);
	return (0);
}

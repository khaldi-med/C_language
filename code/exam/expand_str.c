#include <unistd.h>

void	expand_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		while (s[i] != ' ' && s[i] != '\t' && s[i])
			write(1, &s[i++], 1);
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
		{
			if (s[i] == '\0')
				return ;
			else if (s[i + 1] == ' ' || s[i + 1] == '\t')
			{
				write(1, "   ", 3);
				i++;
			}
			else if (s[i + 1] != ' ' && s[i + 1] != '\t' && s[i])
				write(1, "   ", 3);
		}
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		expand_str(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}

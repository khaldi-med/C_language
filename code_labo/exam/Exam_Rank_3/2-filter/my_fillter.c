#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void	replace_with_asterisks(char *buff, const char *target)
{
	int	match;
	int	target_len;
	int	buff_len;

	target_len = strlen(target);
	buff_len = strlen(buff);
	int i, j;
	for (i = 0; i <= buff_len - target_len; i++)
	{
		match = 1;
		for (j = 0; j < target_len; j++)
		{
			if (buff[i + j] != target[j])
			{
				match = 0;
				break ;
			}
		}
		if (match)
		{
			for (j = 0; j < target_len; j++)
			{
				buff[i + j] = '*';
			}
			i += target_len - 1;
		}
	}
}

int	main(int ac, char **av)
{
	char		buff[4097];
	int			bytes_read;
	const char	*target;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	target = av[1];
	while ((bytes_read = read(0, buff, 4096)) > 0)
	{
		buff[bytes_read] = '\0';
		replace_with_asterisks(buff, target);
		if (write(1, buff, bytes_read) < 0)
		{
			perror("Error writing");
			return (1);
		}
	}
	if (bytes_read < 0)
	{
		perror("Error reading");
		return (1);
	}
	return (0);
}

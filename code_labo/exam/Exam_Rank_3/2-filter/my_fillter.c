#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	buff[10];
	int		total_read;
	char	*result;
	int		av_len;
	int		i;

	total_read = 0;
	if (ac != 2 || av[1][0] == '\0' || av[1][0] == ' ')
		return (1);
	av_len = strlen(av[1]);
	while (1)
	{
		i = 0;
		total_read = read(0, buff, 10);
		if (total_read > 0)
		{
			buff[total_read] = '\0';
			if (total_read == 1 && buff[0] == '\n')
				return (0);
			result = strstr(buff, av[1]);
			if (*result == av[1][0])
			{
				while (av_len)
				{
					result[i] = '*';
					i++;
					av_len--;
				}
				printf("%s", buff);
				/* TODO:
<07-09-25, add function to_asstrick(char *str, int len)> */
			}
		}
		else if (total_read == 0)
		{
			printf("End of input (EOF)\n");
			return (0);
		}
		else
		{
			printf("Error reading input!\n");
			return (1);
		}
	}
	return (0);
}

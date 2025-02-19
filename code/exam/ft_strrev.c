#include "headr.h"

void	ft_strrev(char *s)
{
	char	*start;
	char	*end;
	char	tmp;

	start = s;
	end = s;
	while (*end)
		end++;
	end--;
	while (*s)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end++;
	}
}

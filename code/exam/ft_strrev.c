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
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

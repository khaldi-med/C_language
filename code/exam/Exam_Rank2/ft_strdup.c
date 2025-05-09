#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_s;
	int		i;

	i = 0;
	while (src[i])
		i++;
	new_s = malloc(sizeof(char) * i);
	if (!new_s)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_s[i] = src[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

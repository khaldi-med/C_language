#include <stdio.h>

int	ft_strlen(char *s)
{
	if (*s != '\0')
		return (1 + ft_strlen(++s));
	return (0);
}

int	main(void)
{
	char	*s;

	s = "hello";
	printf("%d", ft_strlen(s));
	return (0);
}

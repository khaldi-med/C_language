#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strchr(const char *s1, int first)
{
	while (*s1)
	{
		if (*s1 == (char)first)
			return ((char *)(s1));
		s1++;
	}
	if (*s1 == (char)first)
		return ((char *)s1);
	return (NULL);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	diff;
	size_t	s_len;

	diff = 0;
	s_len = ft_strlen(s);
	if (!reject || !s)
		return (s_len);
	while (*s)
	{
		if (ft_strchr(reject, *s))
			return (diff);
		else
		{
			diff++;
			s++;
		}
	}
	return (diff);
}

// int	main(int ac, char **av)
// {
// 	if (ac > 2)
// 	{
// 		printf("\nthe diff is: %zu\n", ft_strcspn(av[1], av[2]));
// 		printf("\nthe diff is: %zu\n", strcspn(av[1], av[2]));
// 		// 		printf("\nthe diff is: %d\n", ft_strcmp(av[1], av[2]));
// 	}
// 	return (0);
// }

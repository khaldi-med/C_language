/* ************************************************************************** */
/*   codewars.com                                                             */
/*   to_camel.c                                                               */
/*                                                                            */
/*   Created: 2025/01/22 13:36:54                                             */
/*   Updated: 2025/01/22 13:36:54                                             */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	to_camel_case(const char *text, char *camel)
{
	if (*text == '\0')
		*camel = *text;
	while (*text)
	{
		if ((*text >= 'a' && *text <= 'z') || (*text >= 'A' || *text <= 'Z'))
			*camel++ = *text++;
		else if (*text == '-' || *text == '_')
		{
			text++;
			if (*text >= 'A' && *text <= 'Z')
				*camel++ = *text++;
			else if (*text >= 'a' && *text <= 'z')
				*camel = *text + 'a';
		}
	}
}

int	main(void)
{
	char	*camel;
	camel = NULL;

	to_camel_case("hel_lo", camel);
	printf("%s", camel);
	return (0);
}

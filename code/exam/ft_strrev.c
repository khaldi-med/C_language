#include <stdio.h>

void	ft_strrev(char *s)
{
	char	*start;
	char	*end;
	char	temp;

	if (!s) // Check for NULL pointer
		return ;
	start = s;
	end = s;
	// Move end to the terminating null character
	while (*end)
		end++;
	// If the string is not empty, move end to the last valid character
	if (end != s)
		end--;
	// Swap characters
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Hello, World!";
	str2 = "";
	ft_strrev(str1);
	printf("Reversed str1: %s\n", str1);
	ft_strrev(str2);
	printf("Reversed str2: %s\n", str2);
	ft_strrev(NULL); // Safely does nothing
	return (0);
}

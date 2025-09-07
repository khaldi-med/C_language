#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to replace occurrences of a string with asterisks
void	replace_with_asterisks(char *buffer, int buffer_len, const char *target,
		int target_len)
{
	int	match;

	int i, j;
	for (i = 0; i <= buffer_len - target_len; i++)
	{
		// Check if current position matches the target string
		match = 1;
		for (j = 0; j < target_len; j++)
		{
			if (buffer[i + j] != target[j])
			{
				match = 0;
				break ;
			}
		}
		// If match found, replace with asterisks
		if (match)
		{
			for (j = 0; j < target_len; j++)
			{
				buffer[i + j] = '*';
			}
			// Skip ahead (but -1 because the loop will increment i)
			i += target_len - 1;
		}
	}
}

int	main(int argc, char *argv[])
{
	char		*buffer;
	int			total_read;
	int			bytes_read;
	const char	*target;
	int			target_len;
	char		*new_buffer;

	buffer = NULL;
	int buffer_size = 4096; // Initial buffer size
	total_read = 0;
	// Check for correct number of arguments
	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	target = argv[1];
	target_len = strlen(target);
	// Allocate initial buffer
	buffer = malloc(buffer_size);
	if (!buffer)
	{
		perror("Error: ");
		return (1);
	}
	// Read from stdin
	while ((bytes_read = read(0, buffer + total_read, buffer_size
				- total_read)) >
			0)
	{
		total_read += bytes_read;
		// Check if buffer is full and needs to be resized
		if (total_read == buffer_size)
		{
			buffer_size *= 2;
			new_buffer = realloc(buffer, buffer_size);
			if (!new_buffer)
			{
				free(buffer);
				perror("Error: ");
				return (1);
			}
			buffer = new_buffer;
		}
	}
	// Check for read error
	if (bytes_read < 0)
	{
		free(buffer);
		perror("Error: ");
		return (1);
	}
	// Process the buffer to replace target string with asterisks
	replace_with_asterisks(buffer, total_read, target, target_len);
	// Write processed data to stdout
	if (write(1, buffer, total_read) < 0)
	{
		free(buffer);
		perror("Error: ");
		return (1);
	}
	// Clean up
	free(buffer);
	return (0);
}

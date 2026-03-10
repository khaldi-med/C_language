#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

void	free_json(json j);
int		argo(json *dst, FILE *stream);

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("Unexpected token '%c'\n", peek(stream));
	else
		printf("Unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++   
int	parse_value(json *dst, FILE *stream);

int	parse_int(json *dst, FILE *stream)
{
	int	c;
	int	sign;
	int	n;

	sign = 1;
	n = 0;
	if (accept(stream, '-'))
		sign = -1;
	c = peek(stream);
	if (!isdigit(c))
	{
		unexpected(stream);
		return (-1);
	}
	while (isdigit(peek(stream)))
		n = (n * 10) + (getc(stream) - '0');
	dst->type = INTEGER;
	dst->integer = n * sign;
	return (1);
}

char	*grow_buf(char *str, size_t *cap)
{
	char	*new_str;

	*cap *= 2;
	new_str = realloc(str, *cap);
	if (!new_str)
		free(str);
	return (new_str);
}

char	*get_str(FILE *stream)
{
	char	*res;
	size_t	cap;
	size_t	i;
	int		c;

	if (!accept(stream, '"'))
	{
		unexpected(stream);
		return (NULL);
	}
	cap = 16;
	i = 0;
	res = malloc(cap);
	if (!res)
		return (NULL);
	while ((c = getc(stream)) != EOF)
	{
		if (c == '"')
		{
			res[i] = '\0';
			return (res);
		}
		if (c == '\\')
		{
			c = getc(stream);
			if (c == EOF)
				break ;
			if (c != '\\' && c != '"')
			{
				ungetc(c, stream);
				unexpected(stream);
				free(res);
				return (NULL);
			}
		}
		if (i + 1 >= cap)
		{
			res = grow_buf(res, &cap);
			if (!res)
				return (NULL);
		}
		res[i++] = (char)c;
	}
	free(res);
	unexpected(stream);
	return (NULL);
}

int	parse_map(json *dst, FILE *stream)
{
	char	c;
	char	*key;
	json	value;
	pair	*new_data;

	if (!accept(stream, '{'))
		return (-1);
	dst->type = MAP;
	dst->map.size = 0;
	dst->map.data = NULL;
	if (accept(stream, '}'))
		return (1);
	while (1)
	{
		c = peek(stream);
		if (c != '"')
		{
			unexpected(stream);
			free_json(*dst);
			dst->map.size = 0;
			dst->map.data = NULL;
			return (-1);
		}
		key = get_str(stream);
		if (!key)
		{
			free_json(*dst);
			dst->map.size = 0;
			dst->map.data = NULL;
			return (-1);
		}
		if (!expect(stream, ':'))
		{
			free(key);
			free_json(*dst);
			dst->map.size = 0;
			dst->map.data = NULL;
			return (-1);
		}
		if (parse_value(&value, stream) != 1)
		{
			free(key);
			free_json(*dst);
			dst->map.size = 0;
			dst->map.data = NULL;
			return (-1);
		}
		new_data = realloc(dst->map.data, (dst->map.size + 1) * sizeof(pair));
		if (!new_data)
		{
			free(key);
			free_json(value);
			free_json(*dst);
			dst->map.size = 0;
			dst->map.data = NULL;
			return (-1);
		}
		dst->map.data = new_data;
		dst->map.data[dst->map.size].key = key;
		dst->map.data[dst->map.size].value = value;
		dst->map.size++;
		if (accept(stream, ','))
			continue ;
		if (accept(stream, '}'))
			break ;
		unexpected(stream);
		free_json(*dst);
		dst->map.size = 0;
		dst->map.data = NULL;
		return (-1);
	}
	return (1);
}

int	parse_value(json *dst, FILE *stream)
{
	int	c;

	c = peek(stream);
	if (c == EOF)
	{
		unexpected(stream);
		return (-1);
	}
	if (c == '-' || isdigit(c))
		return (parse_int(dst, stream));
	if (c == '"')
	{
		dst->type = STRING;
		dst->string = get_str(stream);
		if (!dst->string)
			return (-1);
		return (1);
	}
	if (c == '{')
		return (parse_map(dst, stream));
	unexpected(stream);
	return (-1);
}

int argo(json *dst, FILE *stream)
{
	dst->type = MAP;
	dst->map.data = NULL;
	dst->map.size = 0;
	if (parse_value(dst, stream) != 1)
		return (-1);
	if (peek(stream) != EOF)
	{
		unexpected(stream);
		free_json(*dst);
		dst->map.data = NULL;
		dst->map.size = 0;
		return (-1);
	}
	return (1);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	if (!stream)
		return (1);
	json	file;
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return 1;
	}
	serialize(file);
	printf("\n");
}


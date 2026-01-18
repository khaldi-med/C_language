#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// Example 1: Simple sum function
// First parameter indicates how many numbers to sum
int	sum(int count, ...)
{
	va_list	args;
	int		total;

	total = 0;
	// Initialize va_list with the last fixed parameter
	va_start(args, count);
	// Process each variable argument
	for (int i = 0; i < count; i++)
	{
		int value = va_arg(args, int); // Extract next int argument
		total += value;
	}
	// Clean up
	va_end(args);
	return (total);
}

// Example 2: Printf-like function demonstrating va_copy
void	my_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_copy;

	va_start(args, format);
	// Create a copy of the argument list
	va_copy(args_copy, args);
	printf("First pass: ");
	vprintf(format, args);
	printf("Second pass: ");
	vprintf(format, args_copy);
	// Clean up both va_lists
	va_end(args_copy);
	va_end(args);
}

// Example 3: Mixed data types function
void	print_mixed(int count, ...)
{
	va_list	args;
	int		val;
	char	*value;

	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		// First argument tells us the type
		char type = va_arg(args, int); // char is promoted to int
		switch (type)
		{
		case 'i':
		{
			val = va_arg(args, int);
			printf("Integer: %d\n", val);
			break ;
		}
		case 'f':
		{
			double val = va_arg(args, double); // float promoted to double
			printf("Float: %.2f\n", val);
			break ;
		}
		case 's':
		{
			value = va_arg(args, char *);
			printf("String: %s\n", value);
			break ;
		}
		default:
			printf("Unknown type\n");
		}
	}
	va_end(args);
}

// Example 4: Function that uses va_copy to process args twice
double	average_and_max(int count, ...)
{
	va_list	args;
	va_list	args_copy;
	double	sum;
	double	avg;
	double	max;
	double	value;

	va_start(args, count);
	va_copy(args_copy, args);
	// First pass: calculate average
	sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(args, double);
	}
	avg = sum / count;
	// Second pass: find maximum using the copied list
	max = va_arg(args_copy, double);
	for (int i = 1; i < count; i++)
	{
		value = va_arg(args_copy, double);
		if (value > max)
		{
			max = value;
		}
	}
	printf("Average: %.2f, Maximum: %.2f\n", avg, max);
	// Clean up both lists
	va_end(args);
	va_end(args_copy);
	return (avg);
}

// Example 5: String concatenation function
char	*concat_strings(int count, ...)
{
	va_list	args;
	va_list	args_copy;
	int		total_length;
	char	*str;
	char	*s;

	static char result[1000] = {0}; // Static buffer for simplicity
	va_start(args, count);
	va_copy(args_copy, args);
	// First pass: calculate total length needed
	total_length = 0;
	for (int i = 0; i < count; i++)
	{
		str = va_arg(args, char *);
		total_length += strlen(str);
	}
	// Second pass: concatenate strings
	result[0] = '\0'; // Clear the result
	for (int i = 0; i < count; i++)
	{
		s = va_arg(args_copy, char *);
		strcat(result, s);
	}
	va_end(args);
	va_end(args_copy);
	return (result);
}

int	main(void)
{
	char	*result;

	printf("=== Variable Arguments Examples ===\n\n");
	// Example 1: Sum function
	printf("1. Sum function:\n");
	printf("Sum of 3, 7, 2, 8: %d\n", sum(4, 3, 7, 2, 8));
	printf("Sum of 10, 20: %d\n\n", sum(2, 10, 20));
	// Example 2: Printf-like with va_copy
	printf("2. Printf-like function with va_copy:\n");
	my_printf("Hello %s, you are %d years old!\n", "Alice", 25);
	printf("\n");
	// Example 3: Mixed data types
	printf("3. Mixed data types:\n");
	print_mixed(3, 'i', 42, 'f', 3.14, 's', "Hello World");
	printf("\n");
	// Example 4: Average and max
	printf("4. Average and maximum:\n");
	average_and_max(5, 1.5, 2.8, 0.5, 4.2, 3.1);
	printf("\n");
	// Example 5: String concatenation
	printf("5. String concatenation:\n");
	result = concat_strings(4, "Hello", " ", "World", "!");
	printf("Result: %s\n", result);
	return (0);
}

/*
Expected Output:
=== Variable Arguments Examples ===

1. Sum function:
Sum of 3, 7, 2, 8: 20
Sum of 10, 20: 30

2. Printf-like function with va_copy:
First pass: Hello Alice, you are 25 years old!
Second pass: Hello Alice, you are 25 years old!

3. Mixed data types:
Integer: 42
Float: 3.14
String: Hello World

4. Average and maximum:
Average: 2.42, Maximum: 4.20

5. String concatenation:
Result: Hello World!
*/

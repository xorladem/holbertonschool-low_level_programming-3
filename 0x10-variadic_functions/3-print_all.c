#include "variadic_functions.h"
/**
 * print_char - print characters
 * @arguments: input arguments
 */
void print_char(va_list arguments)
{
	printf("%c", va_arg(arguments, int));
}
/**
 * print_string - print strings
 * @arguments: input arguments
 */
void print_string(va_list arguments)
{
	char *args = va_arg(arguments, char *);

	if (args == NULL)
	{
		printf("%p", args);
	}
	printf("%s", args);
}
/**
 * print_float - print floats
 * @arguments: input arguments
 */
void print_float(va_list arguments)
{
	printf("%f", va_arg(arguments, double));
}
/**
 * print_int - print integers
 * @arguments: input arguments
 */
void print_int(va_list arguments)
{
	printf("%i", va_arg(arguments, int));
}
/**
 * print_all - prints anything
 * @format: input string
 */
void print_all(const char * const format, ...)
{
	va_list arguments;

	id_t identifier[] = {
		{'c', print_char},
		{'s', print_string},
		{'f', print_float},
		{'i', print_int}
	};


	int i, j;
	char *comma = "";

	va_start(arguments, format);

	i = 0;
	while (format && format[i])
	{
		j = 0;

		while (j < 4)
		{
			if (identifier[j].all == format[i])
			{
				printf("%s", comma);
				identifier[j].func(arguments);
				comma = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(arguments);
}
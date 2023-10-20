#include"main.h"
/**
 *print_char - prints a character to the standard output.
 * @c:character to be printed
 *
 * Return: number of character printed
 */
static int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string to standar output.
 * @str: string to be printed.
 *
 * Return: number of characters printed
 */
static int print_string(const char *str)
{
	int lenght = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
	write(1, str, 1);
	str++;
	lenght++;
	}
	return (lenght);
}

/**
 * print_format - Processes and prints format specifiers.
 *@format: sting containg format specifiers.
 *@args: Arguments to be fprmatted amd printed.
 *
 * Description:
 * This function processes the format string and optional arguments, handling
 * %c, %s, and %% for printing %. It prints the
 * formatted text to the standard output.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int print_format(const char *format, va_list args)
{
	int to_print = 0;
	char cc;

	while (*format)
	{
		if (*format != '%')
		{
		to_print += print_char(*format);
		}
	else
	{
		format++;
		if (*format == '\0')
			break;

		if (*format == 'c')
		{
			cc = va_arg(args, int);
			to_print += print_char(cc);
		}
		else if (*format == 's')
		{
			char *strg = va_arg(args, char *);

			to_print += print_string(strg);
		}
		else if (*format == '%')
		{
			to_print += print_char('%');
		}
	}
	format++;
	}
	return (to_print);
}

/**
 * _printf - Custom printf function.
 * @format: Format string containing format specifiers.
 * @...: Arguments to be formatted and printed.
 *
 * Description: This function prints formatted text to the standard output
 * using a format string and optional arguments. It supports %c for characters
 * and %s for strings.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int to_print = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	to_print = print_format(format, args);
	va_end(args);
	return (to_print);
}




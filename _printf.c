#include"main.h"
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
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
to_print++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == '%')
{
write(1, format, 1);
to_print++;
}
else if (*format == 'c')
{
char cc = va_arg(args, int);
write(1, &cc, 1);
to_print++;
}
else if (*format == 's')
{
char *strg = va_arg(args, char*);
int lenght = strlen(strg);
write(1, strg, lenght);
to_print += lenght;
}
}
format++;
}
va_end(args);
return (to_print);
}

#include"main.h"

/**
 * _printf_1 - Custom printf function to print integers
 * @format: Format string with %d and %i specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf_1(const char *format, ...)
{
va_list args;
int int_print = 0;
va_start(args, *format);
if (format == NULL)
{
return (-1);
}
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
int_print++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
int len = snprintf(NULL, 0, "%d", num);
char *buffer = malloc(len + 1);
if (buffer == NULL)
{
return (-1);
}
snprintf(buffer, len + 1, "%d", num);
write(1, buffer, len);
int_print += len;
free(buffer);
}
}
format++;
}
va_end(args);
return (int_print);
}

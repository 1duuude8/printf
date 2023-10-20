#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
 * print_char - Prints a character to the standard output.
 * @c: Character to be printed.
 *
 * Return: Number of characters printed (always 1).
 */
int print_char(char c)
{
    write(1, &c, 1);
    return 1;
}

/**
 * print_string - Prints a string to the standard output.
 * @str: String to be printed.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int print_string(char *str)
{
    int length = 0;
    if (str == NULL)
    {
        write(1, "(null)", 6);
        length = 6;
    }
    else
    {
        while (*str)
        {
            write(1, str, 1);
            str++;
            length++;
        }
    }
    return length;
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
        return -1;

    va_start(args, format);

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
            if (*format == '%')
            {
                to_print += print_char('%');
            }
            else if (*format == 'c')
            {
                char cc = va_arg(args, int);
                to_print += print_char(cc);
            }
            else if (*format == 's')
            {
                char *strg = va_arg(args, char *);
                to_print += print_string(strg);
            }
            else
            {
                to_print += print_string("(null)");
            }
        }
        format++;
    }

    va_end(args);
    return to_print;
}

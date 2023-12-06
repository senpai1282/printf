#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - generate output according to format
 * @format: A string containing characters and specifiers
 *
 * Description:
 * This function mimics the basic functionality of printf by handling
 * conversion specifiers %c, %s, and %%.
 * For %c, it fetches a character argument and prints it using putchar.
 * For %s, it fetches a string argument and prints each character.
 * For %%, it prints a single % character.
 *
 * Return:
 * The number of characters printed (excluding the null)
 */

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
	{
        if (*format == '%') 
		{
            format++;
            if (*format == 'c')
			{
                int c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            } else if (*format == 's')
			{
                char *s = va_arg(args, char*);
                while (*s)
				{
                    putchar(*s);
                    printed_chars++;
                    s++;
                }
            } else if (*format == '%')
			{
                putchar('%');
                printed_chars++;
            }
			else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                printf("%d", num);
                printed_chars += snprintf(NULL, 0, "%d", num);
            }
        else 
		{
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}
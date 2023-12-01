#include "main.h"
#include <stdio.h>

/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...) {
	va_list args;
	int count = 0;

	va_start(arge, format);

	while (*format != '/0') {
		if (*format == '%') {
			format++;
			if (*format == 'c') {
				char character = va_arg(args, int);
				putchar(character);
				count++;
			} else if (*format == 's') {
				const char *str = va_arg(args, const char *);
				while (*str != '\0') {
					putchar(*str);
					str++;
					}
				} else if (*format == '%') {
					putchar('%');
					count++;
					}
			} else {
				putchar(*format);
				count++;
				}
		format++;
		}
	va_end(args);
	return count;
	}

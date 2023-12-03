#include <main.h>
#include <stdio.h>

/**
 * _printf > Produces output according to the format
 * @format: A character string containing zero or more directives
 *
 * Return: The number of bytes printed
*/

int _printf(const char *format, ...)
	{
		int sum = 0;
		va_list ap;
		char *p, *start;
		params_t params = PARAMS_INIT;

		if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
		_putchar(-1);
		va_end(arguments);
		return (count);
	}

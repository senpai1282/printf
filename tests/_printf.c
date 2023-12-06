#include "main.h"
/**
 * _printf - print fn chars to stdout
 * @format: format specifier for program
 * Return: no of bytes printed yes
 */
int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
unsigned int i, s_count, count = 0;

va_list args;

va_start(args, format);

if (format == NULL)
return (-1);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
putsmychar(format[i]);
}

else if (format[i + 1] == '%')
{
putsmychar('%');
i++;
}

else if (format[i + 1] == 'b')
{
bi_calc(va_arg(args, unsigned int));
i++;
}

else if (format[i + 1] == 'c')
{
putsmychar(va_arg(args, int));
i++;
}

else if (format[i + 1] == 'd')
{
convert_this(va_arg(args, int));
i++;
}

else if (format[i + 1] == 'i')
{
convert_this(va_arg(args, int));
i++;
}

else if (format[i + 1] == 's')
{
s_count = putsmystring(va_arg(args, char *));
i++;
count += (s_count - 1);
}

count += 1;
}
va_end(args);
return (count);
}
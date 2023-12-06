#include <stdio.h>
#include  <stdarg.h>

/**
 * _printf - produces output according to a format
 * @con_char - calculate the number of character printed
 * this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * Return: length of the formatted output string
**/

int _printf(const char *format, ...)
{
	int con_char;
	va_list args;
	va_start(args, format);

	con_char = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c': {
						  char c = (char) va_arg(args, int);
						  putchar (c);
						  con_char++;
					  }
						  break;
			case 's': {
					  const char *s = va_arg(args, const char *);
					  while (*s != '\0')
					  {
						  putchar(*s);
						  s++;
						  con_char++;
				 	  }
					  break;
				  }
			case '%':
				  putchar('%');
				  con_char++;
				  break;
			case 'd':
				  case 'i': {
						    int num = va_arg(args, int);
						    printf("%d", num);
						    con_char++;
						    break;
					    }
				 case 'u': {
						   unsigned int num = va_arg(args, unsigned int);
						   printf("%u", num);
						   con_char++;
						    break;
					   }
				  case 'o': {
						    unsigned int num = va_arg(args, unsigned int);
						    printf("%o", num);
						    con_char++;
						    break;
					    }
				 case 'x':
					     case 'X': {
							       unsigned int num = va_arg(args, unsigned int);
							       printf("%x", num);
							       con_char++;
							        break;
						       }
					     case 'p': {
							       void *ptr = va_arg(args, void *);
							       printf("%p", ptr);
							       con_char++;
							       break;
						       }
				              default:
						        putchar('%');
							putchar(*format);
							con_char += 2;
							break;
			}

		} else {
			putchar(*format);
			con_char++;
		}
		format++;
	}
	va_end(args);
	return con_char;
}
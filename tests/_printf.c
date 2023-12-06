#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: a string containing the characters and the specifiers
 * Description: calls the print_char function that will
 * determine which printing function to call depending on the conversion
 * 
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
    
    int print_char = 0;
    va_list arg_lists;

      if(format == NULL)
        RETURN (-1);

    va_start(arg_lists, format);

    while(*format)
    {
        if(*format != '%') /*if format is not %*/ 
        {
            write(1, format, 1); /*write the character to the right output*/
            print_char++;
        }
        else /*if the charcter format is not the % sign*/
        {
            format++; /*skip % - check for next character*/
        
        
            if(*format == '\0')
                break;  
            
            if(*format == '%') /*handle %.*/
            {
                /*handle '%%'*/
                write(1, format, 1);
                print_char++;
            }
            else if(*format == 'c') /*handle c.*/
            {
                char c = va_arg(arg_lists, int); /*used for char*/
                write(1, &c, 1);
                print_char++;
            }
            else if (*format == 's') /*handle s.*/
            {
                char *str = va_arg(arg_lists, char*);
                int str_len = 0;
                /*calc the strg length.*/
                while(str[str_len] != '\0')
                str_len++;
                /*write strg to stdrd output.*/
                write(1, str, str_len);
                print_char += str_len;
            }
        }
        format++;
    }
    va_end(arg_lists);
    return print_char;
}

int main(){
    _printf("leo\n");
    _printf("%c\n", 'v');
    _printf("%s\n", 'string');
    _printf("%%\n");
    return 0;
}
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
				{
					int num = va_arg(args, int);
					printf("%d", num);
					con_char++;
					break;
				}
				case 'u': 
				{
					unsigned int num = va_arg(args, unsigned int);
					printf("%u", num);
					con_char++;
					break;
				}
				case 'o': 
				{
					unsigned int num = va_arg(args, unsigned int);
					printf("%o", num);
					con_char++;
					break;
				}
				case 'X': 
				{
					unsigned int num = va_arg(args, unsigned int);
					printf("%x", num);
					con_char++;
					break;
				}
				case 'p':
				{
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

		} else
		{
			putchar(*format);
			con_char++;
		}
		format++;
	}
	va_end(args);
	return con_char;
}
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
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
    _printf("%s\n", 's');
    _printf("%%\n");
    return 0;
}
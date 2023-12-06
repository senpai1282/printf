#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: A string containing characters and specifiers
 *
 * Description:
 * This function handles conversion specifiers %c, %s, %%, %d, and %i.
 * For %c, %s, and %% it outputs the corresponding characters.
 * For %d and %i, it converts integers to strings and outputs.
 *
 * Return:
 * The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...) {
    int print_char = 0;
    va_list arg_lists;

    if (format == NULL)
        return (-1);

    va_start(arg_lists, format);

    while (*format) {
        if (*format != '%') {
            write(1, format, 1);
            print_char++;
        } else {
            format++;
            if (*format == '\0')
                break;
            
            if (*format == '%') {
                write(1, format, 1);
                print_char++;
            } else if (*format == 'c') {
                char c = va_arg(arg_lists, int);
                write(1, &c, 1);
                print_char++;
            } else if (*format == 's') {
                char *str = va_arg(arg_lists, char*);
                int str_len = 0;
                while (str[str_len] != '\0')
                    str_len++;
                write(1, str, str_len);
                print_char += str_len;
            } else if (*format == 'd' || *format == 'i') {
                int num = va_arg(arg_lists, int);
                int temp = num;
                int digits = 0;
                if (temp <= 0) {
                    digits = 1;
                    temp = -temp;
                }
                while (temp != 0) {
                    temp /= 10;
                    digits++;
                }
                char buffer[digits + 1];
                snprintf(buffer, sizeof(buffer), "%d", num);
                write(1, buffer, digits);
                print_char += digits;
            }
        }
        format++;
    }
    va_end(arg_lists);
    return print_char;
}
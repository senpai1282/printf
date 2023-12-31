#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Produces output according to a format
 * @format: A string containing characters and specifiers
 *
 * Description:
 * This function handles conversion specifiers %c, %s, and %%.
 * It outputs characters and strings as specified by the format string.
 *
 * Return:
 * The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...) {
    if (format == NULL) return -1; // Error check for NULL format string

    int con_char = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format);
            con_char++;
        } else {
            format++;
            if (*format == '\0') break; // Handle % at the end of the string

            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    con_char++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    if (s != NULL) {
                        while (*s != '\0') {
                            putchar(*s);
                            s++;
                            con_char++;
                        }
                    } else {
                        printf("(null)"); // Handle NULL string
                        con_char += 6; // Length of "(null)"
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    con_char++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    con_char += 2;
                    break;
            }
        }
        format++;
    }
    va_end(args);
    return con_char;
}

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <studio.h>
#include <unistd.h>
#include <limits.h>
#include <standlib.h>

#define OUTPUT_BUF_SIZE 1024
#define buf_flush -1

#define NULL_STRING "(null)"
#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT_LOWERCASE
#define CONVERT_UNSIGNED

/**
 * 
 *
 *
 */

typedef struct paramerters
{
	unsigned int unsign	: 1;

	unsigned int plus_flag	: 1;
	unsigned int space_flag	: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag	: 1;
	unsigned int minus_flag	: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier	: 1;
	unsigned int l midifier	: 1;
} params_t;

/**
 *
 *
 *
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/*_put.c module */
int _puts(char *str);
int _putchar(int c);

/*print_function.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_persent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, param_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params.t *params);
int print_adress(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specefier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int _printf(const char *format, ...);

#endif

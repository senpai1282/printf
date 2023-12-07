#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * str_format - Struct op
 * typedef str_format format_t - Struct op
 * 
 * @format: The format.
 * @function: The function associated.
 */
str_format
{
	char format;
	int (*function)(va_list, char[], int, int, int, int);
};

typedef str_format format_t;

int _printf(const char *format, ...);
int rint_handler(const char *format, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* functions */

/* print chars and strings */
int char_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int str_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pers_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print numbers */
int int_prints(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int hexa_print(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* print non printable characters */
int non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print memory address */
int pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*  handle other specifiers */
int get_flag(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*print string in rot 13*/
int rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */


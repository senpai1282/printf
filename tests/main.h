#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int putsmystring(char *c);
int convert_this(int zdnum);
unsigned int bi_calc(unsigned int bnum);
int putsmychar(char c);
int _printf(const char *format, ...);

#endif

#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);

#endif
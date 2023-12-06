#include "main.h"
#include <stdio.h>
/**
 * putchar_writer - %d, %i int conversions to decimal
 * @x: int to be modded to decimal
 * @scount: total printed character count
 * Return: my converted int as decimal
 **/
int putchar_writer(int x, int scount)
{
int c = x;

if (x < 0)
{
c = -x;
putsmychar('-');
scount = scount + 1;
}

if (c / 10)
{
scount = putchar_writer(c / 10, scount);
}

/** count = count + 1; **/

putsmychar(c % 10 + '0');

return (scount + 1);
}


/******************************************/

/**
 * dnum - handles int to base10 con
 * @num: int parsed for conv
 * Return: int conversin through putchar_writer
 **/
int dnum(int num)
{
return (putchar_writer(num, 0));
}

/**
 * convert_this - major function for int to base10 con
 * @zdnum: character specifier between %d and %i
 * Return: address of proper function
 **/
int convert_this(int zdnum)
{
return (dnum(zdnum));
}
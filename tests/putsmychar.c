#include "main.h"
/**
 * putsmychar - print a character value
 * @c: char input to process here
 * Return: 1 always
 */
int putsmychar(char c)
{
return (write(1, &c, 1));
}
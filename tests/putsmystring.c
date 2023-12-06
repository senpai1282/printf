#include "main.h"
/**
 * putsmystring- prints a *char string
 * @c: string to print
 * Return: number of bytes printed
 */
int putsmystring(char *c)
{
	int char_count = 0;

	if (c)
	{
		for (char_count = 0; c[char_count] != '\0'; char_count++)
		{
			putsmychar(c[char_count]);
		}
	}
	return (char_count);
}
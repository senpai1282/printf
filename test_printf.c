#include "main.h"
#include <stdio.h>

int main(void) {
    int chars_printed;

    /* Test case 1: Printing a line with '_' */
    chars_printed = _printf("Printing a line with underscores: ");
    _printf("\nTotal characters printed: %d\n\n", chars_printed);

    /* Test case 2: Printing an empty line */
    chars_printed = _printf("Printing an empty line: %d", 0);
    _printf("\nTotal characters printed: %d\n\n", chars_printed);

    /* Test case 3: Printing a single character */
    chars_printed = _printf("Printing a single character: %c", 'A');
    _printf("\nTotal characters printed: %d\n\n", chars_printed);

    return (0);
}

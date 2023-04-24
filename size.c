#include "main.h"

/**
 * size - Calculates the size to print the argument
 * @format: Formatted string to print the arguments
 * @i: List of arguments to be printed
 *
 * Return: Precision
 */
int size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sze = 0;

	if (format[curr_i] == 'l')
		sze = S_LONG;
	else if (format[curr_i] == 'h')
		sze = S_SHORT;

	if (sze == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sze);
}

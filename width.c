#include "main.h"

/**
 * width - Calculates the width
 * @format: Formatted string in which to print
 * @i: List of arguments to print
 * @list: list of arguments
 *
 * Return: width
 */
int width(const char *format, int *i, va_list list)
{
	int curr_i;
	int wdth = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			wdth *= 10;
			wdth += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			wdth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (wdth);
}

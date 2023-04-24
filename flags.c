#include "main.h"

/**
* get_flags - Calculates active flags
* @format: Formatted string in which to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int flags(const char *format, int *i)
{
	int j, curr_i;
	int flg = 0;
	const char flag_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_arr[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
	for (j = 0; flag_ch[j] != '\0'; j++)
	if (format[curr_i] == flag_ch[j])
	{
	flg |= flag_arr[j];
	break;
	}

	if (flag_ch[j] == 0)
		break;
	}

	*i = curr_i - 1;

	return (flg);
}

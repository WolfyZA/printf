#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sze: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flg, wdth, prec, sze));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sze: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sze);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prec >= 0 && prec < length)
		length = prec;

	if (wdth > length)
	{
		if (flg & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = wdth - length; i > 0; i--)
				write(1, " ", 1);
			return (wdth);
		}
		else
		{
			for (i = wdth - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wdth);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sze: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sze);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sze: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flg, wdth, prec, sze));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sze: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sze);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

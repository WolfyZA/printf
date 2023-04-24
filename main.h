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
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flg, int wdth, int prec, int sze);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_string(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_percent(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_binary(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_unsigned(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_octal(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_hexadecimal(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);
int print_hexa_upper(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);

int print_hexa(va_list types, char map_to[],
char buffer[], int flg, char flag_ch, int wdth, int prec, int sze);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);

/* Functions to handle other specifiers */
int flags(const char *format, int *i);
int width(const char *format, int *i, va_list list);
int precision(const char *format, int *i, va_list list);
int size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flg, int wdth, int prec, int sze);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flg, int wdth, int prec, int sze);
int write_number(int is_positive, int ind, char buffer[],
	int flg, int wdth, int prec, int sze);
int write_num(int ind, char bff[], int flg, int wdth, int prec,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int wdth, int flg, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flg, int wdth, int prec, int sze);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int sze);
long int convert_size_unsgnd(unsigned long int num, int sze);

#endif /* MAIN_H */


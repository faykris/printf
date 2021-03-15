#include "holberton.h"

/**
 * copy_string - process the s format identifier
 * and copy it in secondary buffer
 *
 * @sbuffer: buffer to be filled with arg
 * @format: format to be aplied in buffer before return it.
 * @param_list: list of arguments
 *
 * Return: pointer to secondary buffer.
 */
char *copy_string(char *sbuffer, char *format, va_list param_list)
{
	char *argument = va_arg(param_list, char *);

	if (argument == NULL)
		_strncat(sbuffer, "(null)", 1024);
	else
	_strncat(sbuffer, argument, 1024);

	format[0] = '\0';
	/* aply format */

	return (sbuffer);
}

/**
 * copy_char - process the c format identifier
 * and copy it in secondary buffer
 *
 * @sbuffer: buffer to be filled with arg
 * @format: format to be aplied in buffer before return it.
 * @param_list: list of arguments
 *
 * Return: pointer to secondary buffer.
 */
char *copy_char(char *sbuffer, char *format, va_list param_list)
{
	char s = va_arg(param_list, char *);
		_strncat(sbuffer, &s, 1);
	format[0] = '\0';
	/* aply format */

	return (sbuffer);
}

/**
 * copy_int - copies the number in a secondary buffer.
 *
 * @sbuffer: pointer to string.
 * @format: format of the string.
 * @param_list: list of parameters entering variadic.
 *
 * Return: pointer to secondary buffer.
 */
char *copy_int(char *sbuffer, char *format, va_list param_list)
{
	int number = va_arg(param_list, int);

	if (number < 0)
		sbuffer[0] = '-';
	format[0] = '\0';
	dec_converter(number, sbuffer, 10);

	return (sbuffer);
}


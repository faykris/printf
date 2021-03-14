#include "holberton.h"

/**
 * copy_string -
 *
 * @ptr_to_percent: pointer to string.
 * @param_list: list of arguments
 *
 * Return: pointer to secondary buffer
 */
char *copy_string(char *sbuffer, char *format, va_list param_list)
{

	_strncat(sbuffer, va_arg(param_list, char *), 1024);

	/* aply format */

	return (sbuffer);
}

char *copy_char(char *sbuffer, char *format, va_list param_list)
{
	char s = va_arg(param_list, char *);
		_strncat(sbuffer, &s, 1);

	/* aply format */

	return (sbuffer);
}

char *copy_int(char *sbuffer, char *format, va_list param_list)
{

}




#include "holberton.h"

/**
 * process_reverse - copies reversed string into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_reverse(char *sbuffer, char *format, va_list param_list)
{
	char *argument = va_arg(param_list, char *);

	if (argument == NULL)
		_strncat(sbuffer, "(null)", 1024);
	else
	{
		_strncat(sbuffer, argument, 1024);
		rev_string(sbuffer);
	}

	format[0] = '\0';
	/* aply format */

	return (sbuffer);
}

/**
 * process_root13 - copies root 13 string conversion into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_root13(char *sbuffer, char *format, va_list param_list)
{
	char *argument = va_arg(param_list, char *);
	int i = 0;

	if (argument == NULL)
		_strncat(sbuffer, "(null)", 1024);
	else
	{
		_strncat(sbuffer, argument, 1024);
		for (; sbuffer[i]; i++)
		{
			if (('a' <= sbuffer[i] && sbuffer[i] <= 'm') ||
				('A' <= sbuffer[i] && sbuffer[i] <= 'M'))
				sbuffer[i] += 13;
			else if (('n' <= sbuffer[i] && sbuffer[i] <= 'z') ||
				('N' <= sbuffer[i] && sbuffer[i] <= 'Z'))
				sbuffer[i] -= 13;
		}
	}

	format[0] = '\0';
	/* aply format */

	return (sbuffer);
}


/**
 * _width - adds width to the data.
 * @sbuffer: buffer to be filled with arg
 * @format: format to be aplied in buffer before return it.
 * @argument: list of arguments
 *
 * Return: None.
 */
void _width(char *sbuffer, char *format, char *argument)
{
	int index = 5, num = 0, diferencia = 0;
	int p = 0;

	for (; *(format + index); index++)
	{
		if (*(format + index) > '0' && *(format + index) <= '9')
			p = 1;
		if (*(format + index) >= '0' && *(format + index) <= '9')
		{
			num = num * 10 + (*(format + index) - '0');
		}
		else if (p == 1)
		{
			break;
		}
	}
	diferencia = num - _strlen(argument);
	if (diferencia > 0)
	{
		for (index = 0; index < diferencia; index++)
		{
			_strncat(sbuffer, " ", 10024);
		}
	}
}

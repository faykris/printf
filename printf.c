#include "holberton.h"

/**
 * _printf -
 *
 * @format:
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format1,...)
{
	char *format=(char *) format1;
	char *buffer = NULL, *format_pos;
	va_list param_list;
	int index_format, return_steps;

	if (format == NULL)
		return (-1);

	buffer = malloc(1024);
	if (!buffer)
		return (-1);/* confirmar */

	buffer[0]='\0';
	va_start(param_list, format1);

	for (index_format = 0; format[index_format]; index_format++)
	{
		format_pos = format + index_format;
		if ( *format_pos == '%' && *(format_pos + 1) == '%')
			_strncat(buffer, format + (++index_format), 1);
		else if (*format_pos != '%')
			_strncat(buffer, format_pos, 1);
		else
		{
			return_steps = steps(format_pos, param_list, buffer);
			if (return_steps == 0)
				_strncat(buffer, format_pos, 1);
			else
				index_format += (return_steps);
		}

	}

	va_end(param_list);
	return (_write(buffer));
}

#include "holberton.h"

/**
 * _printf - format and print data
 *
 * @format: arguments data to be printed
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format, ...)
{
	char *format1 = (char *) format;
	char *buffer = NULL, *format_pos;
	va_list param_list;
	int index_format, ret_steps;

	if (format1 == NULL)
		return (-1);

	buffer = malloc(1024);
	if (!buffer)
		return (-1);

	buffer[0] = '\0';
	va_start(param_list, format);

	for (index_format = 0; format[index_format]; index_format++)
	{
		format_pos = format1 + index_format;
		if (*format_pos == '%' && *(format_pos + 1) == '%')
			_strncat(buffer, format1 + (++index_format), 1);
		else if (*format_pos != '%')
			_strncat(buffer, format_pos, 1);
		else
		{
			ret_steps = find_format(format_pos, param_list, buffer);
			if (ret_steps == 0)
				_strncat(buffer, format_pos, 1);
			else
				index_format += (ret_steps);
		}
	}
	va_end(param_list);
	return (_write(buffer));
}


/**
 * find_format - check for valid format in the string
 *
 * @ptr_to_percent:pointer to % simbol in format string
 * @param_list: list of parameters entering variadic.
 * @buffer: pointer to response string
 *
 * Return: number of processed format characters
 */
int find_format(char *ptr_to_percent, va_list param_list, char *buffer)
{
	char sp_chars[] = "%scdiSb";
	int index_format, index_sp_chars;
	char *format_buffer, *fbc;

	for (index_format = 1; ptr_to_percent[index_format]; index_format++)
	{/*itera hasta encontrar un caracter especial o un caeacter nulo*/
		for (index_sp_chars = 0; sp_chars[index_sp_chars]; index_sp_chars++)
		{/*itera para cada caracter especial */

			if (ptr_to_percent[index_format] == sp_chars[index_sp_chars])
			{/*hubo una coincidencia con un caracter especial*/

				format_buffer = malloc(250);
				if (format_buffer == NULL)
				{
					free(buffer);
					exit(98);
				}
				format_buffer[0] = '\0';

				fbc = get_format(ptr_to_percent, format_buffer, index_format);
				if (fbc == NULL)
				{
					free(format_buffer);
					return (0);
				}
				if (sp_chars[index_sp_chars] == '%')
				{
					_strncat(buffer, "%", 1024);
					return (index_format);
				}

				append_arg(buffer, format_buffer, sp_chars[index_sp_chars], param_list);
				return (index_format);
			}
		}
	}
	/*no se encontro caracter especial*/
	return (0);
}

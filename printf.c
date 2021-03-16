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

	buffer = malloc(sizeof(char) * 1024);
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
			else if (ret_steps == -1)
			{
				_write(buffer);
				return (-1);
			}
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
 * @ptr_2_p:pointer to % simbol in format string
 * @param_list: list of parameters entering variadic.
 * @buffer: pointer to response string
 *
 * Return: number of processed format characters
 */
int find_format(char *ptr_2_p, va_list param_list, char *buffer)
{
	char *format_buffer, *fbc, sp_chars[] = "%scdiSbpuoxXrR";
	int index_format, index_sp_chars, indexFallo[1];

	*indexFallo = 0;
	for (index_format = 1; 1 ; index_format++)
	{/*itera hasta encontrar un caracter especial o un caeacter nulo*/
		for (index_sp_chars = 0; sp_chars[index_sp_chars]; index_sp_chars++)
		{/*itera para cada caracter especial */
			if (ptr_2_p[index_format] == sp_chars[index_sp_chars] ||
				!ptr_2_p[index_format])
			{/*hubo una coincidencia con un caracter especial*/
				format_buffer = malloc(250);
				if (format_buffer == NULL)
				{	free(buffer);
					exit(98);
				}
				format_buffer[0] = '\0';
				fbc = get_format(ptr_2_p, format_buffer,
					index_format, indexFallo);
				if (fbc == NULL)
				{
					if (ptr_2_p[index_format] == sp_chars[index_sp_chars])
					{	free(format_buffer);
						return (0);
					}	translate_format(buffer, format_buffer);
					free(format_buffer);
					return (*indexFallo - 1);
				}
				if (!ptr_2_p[index_format])
				{	free(format_buffer);
					return (-1);
				}
				if (sp_chars[index_sp_chars] == '%')
				{	_strncat(buffer, "%", 1024);
					return (index_format);
				}
				append_arg(buffer, format_buffer,
					sp_chars[index_sp_chars], param_list);
				return (index_format);
			}	}	} return (0); }

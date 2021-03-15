#include "holberton.h"

/**
 * _printf - format and print data
 *
 * @format1: arguments data to be printed
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format1, ...)
{
	char *format = (char *) format1;
	char *buffer = NULL, *format_pos;
	va_list param_list;
	int index_format, ret_steps;

	if (format == NULL)
		return (-1);

	buffer = malloc(1024);
	if (!buffer)
		return (-1);

	buffer[0] = '\0';
	va_start(param_list, format1);

	for (index_format = 0; format[index_format]; index_format++)
	{
		format_pos = format + index_format;
		if (*format_pos == '%' && *(format_pos + 1) == '%')
			_strncat(buffer, format + (++index_format), 1);
		else if (*format_pos != '%')
			_strncat(buffer, format_pos, 1);
		else
		{
			ret_steps = steps(format_pos, param_list, buffer);
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
 * select_func - Select fuctions depending data type
 *
 * @specifier: pointer to string.
 *
 * Return: pointer tocopy_function selected
 */
char *(*select_func(char specifier))(char *, char *, va_list)
{
	copy_func array_copy_func[] = {
		{'s', copy_string},
		{'c', copy_char},
		{'d', copy_int},
		{'i', copy_int},
		{'b', copy_binary},
		{'S', copy_custom_string},
		{'f', copy_float}
	};

	int index = 0;

	while (specifier != array_copy_func[index].esp)
	{
		index++;
	}
	return (array_copy_func[index].ptr_func);
}

/**
 * clean_format - clear value of format
 *
 * @ptr_to_percent: pointer with percent
 * @buffer_format: pointer buffer format
 * @index_spc: integer indicates special character
 *
 * Return: pointer tocopy_function selected
 */
char *clean_format(char *ptr_to_percent, char *buffer_format, int index_spc)
{
	int index, index_buffer = 4, id_sec = 0, has_point = 0, index_val;
	char val_chars[] = "-+ 0";

	buffer_format[0] = buffer_format[1] = '0';
	buffer_format[2] = buffer_format[3] = '0';
	for (index = 1; index < index_spc; index++)
	{
		for (index_val = 0; val_chars[index_val]; index_val++)
		{
			if (ptr_to_percent[index] == val_chars[index_val])
			{
				if (id_sec)
				{
					if (val_chars[index_val] != 0)
						return (NULL);
					buffer_format[index_buffer++] = '0';
					break;
				}	buffer_format[index_val] = '1';
				break;
			}
		}
		if (index_val > 3)
		{
			if (ptr_to_percent[index] == '.')
			{
				if (has_point)
					return (NULL);
				buffer_format[index_buffer++] = '.';
				id_sec = 1;
				has_point = 1;
			}
			else if ('0' < ptr_to_percent[index] && ptr_to_percent[index] <= '9')
			{	id_sec = 1;
				buffer_format[index_buffer++] = ptr_to_percent[index];
			}	else
				return (NULL);
		}
	}
	buffer_format[index_buffer] = '\0';
	return (buffer_format);
}

#include "holberton.h"

/**
 * append_arg - appends the text processed by the process_functions
 *
 * @buffer: pointer to response string
 * @format: format of the string.
 * @sp_char: character as specifier of format
 * @param_list: list of parameters entering variadic.
 *
 * Return: nothing
 */
void append_arg(char *buffer, char *format, char sp_char, va_list param_list)
{
	char *(*ptr_func)(char *sbuffer, char *format, va_list param_list);
	char *sbuffer;

	ptr_func = select_func(sp_char);

	sbuffer = malloc(1024);
	if (sbuffer == NULL)
	{
		free(buffer);
		free(format);
		exit(98);
	}
	sbuffer[0] = '\0';

	ptr_func(sbuffer, format, param_list);

	_strncat(buffer, sbuffer, 1024);

	free(sbuffer);
	free(format);
}


/**
 * get_format - clear value of format
 *
 * @ptr_to_percent: pointer with percent
 * @format: pointer buffer format
 * @index_spc: integer indicates special character
 * @indexFallo: integer indicate where it fail
 *
 * Return: pointer to format buffer
 */
char *get_format(char *ptr_to_percent, char *format,
	int index_spc, int *indexFallo)
{
	int index, index_buffer = 4, id_sec = 0, has_point = 0, index_val;
	char val_chars[] = "-+ 0";

	format[0] = format[1] = format[2] = format[3] = '0';
	for (index = 1; index < index_spc; index++)
	{
		for (index_val = 0; val_chars[index_val]; index_val++)
		{
			if (ptr_to_percent[index] == val_chars[index_val])
			{
				if (!id_sec)
				{	format[index_val] = '1';
					break;
				}
			}
		}
		if (index_val > 3)
		{
			if (ptr_to_percent[index] == '.')
			{
				if (has_point)
				{*indexFallo = index;
					return (NULL);
				}
				format[index_buffer++] = '.';
				id_sec = 1;
				has_point = 1;
			}	else if ('0' <= ptr_to_percent[index] && ptr_to_percent[index] <= '9')
			{	id_sec = 1;
				format[index_buffer++] = ptr_to_percent[index];
			}	else
			{	*indexFallo = index;
				return (NULL);
			}
		}
	}
	format[index_buffer++] = ptr_to_percent[index_spc];
	format[index_buffer] = '\0';
	return (format);
}


/**
 * select_func - Select fuctions depending data type
 *
 * @specifier: pointer to string.
 *
 * Return: pointer toprocess_function selected
 */
char *(*select_func(char specifier))(char *, char *, va_list)
{
	process_func array_process_func[] = {
		{'s', process_string},
		{'c', process_char},
		{'d', process_int},
		{'i', process_int},
		{'b', process_binary},
		{'S', process_custom_string},
		{'f', process_float},
		{'p', process_pointer},
		{'x', process_hex},
		{'X', process_hex},
		{'r', process_reverse},
		{'R', process_root13},
	};

	int index = 0;

	while (specifier != array_process_func[index].esp)
	{
		index++;
	}
	return (array_process_func[index].ptr_func);
}


/**
 * _write - writes the characters to stdout.
 * @buffer: The string to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write(char *buffer)
{
	int len = 0, bytes_printed;

	while (buffer[len])
	{
		if (buffer[len] == 1)
			buffer[len] = 0;
		len++;
	}
	bytes_printed = write(1, buffer, len);

	free(buffer);
	buffer = "";
	return (bytes_printed);
}

#include "holberton.h"

/**
 * steps - check for valid format in the string
 *
 * @ptr_to_percent:pointer to % simbol in format string
 * @param_list: list of parameters entering variadic.
 * @buffer: pointer to response string
 *
 * Return: number of processed format characters
 */
int steps(char *ptr_to_percent, va_list param_list, char *buffer)
{
	char sp_chars[] = "scdiSb";
	int index_format, index_sp_chars;
	char *format_buffer, *fbc;

	for (index_format = 1; ptr_to_percent[index_format] &&
		ptr_to_percent[index_format] != '%'; index_format++)
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

				fbc = clean_format(ptr_to_percent, format_buffer, index_format);

				if (fbc == NULL)
				{
					free(format_buffer);
					return (0);
				}
				string_copy(buffer, format_buffer, sp_chars[index_sp_chars], param_list);
				return (index_format);
			}
		}
	}

	/*no se encontro caracter especial*/
	return (0);
}





/**
 * string_copy - appends the text processed by the copy_functions
 *
 * @buffer: pointer to response string
 * @format: format of the string.
 * @sp_char: character as specifier of format
 * @param_list: list of parameters entering variadic.
 *
 * Return: nothing
 */
void string_copy(char *buffer, char *format, char sp_char, va_list param_list)
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

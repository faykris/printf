#include "holberton.h"

/**
 * process_string - process the s format identifier
 * and copy it in secondary buffer
 *
 * @sbuffer: buffer to be filled with arg
 * @format: format to be aplied in buffer before return it.
 * @param_list: list of arguments
 *
 * Return: pointer to secondary buffer.
 */
char *process_string(char *sbuffer, char *format, va_list param_list)
{

	char *argument = va_arg(param_list, char *);

	if (argument == NULL)
		_strncat(sbuffer, "(null)", 10240);
	else
	_strncat(sbuffer, argument, 10024);

	format[0] = '\0';
	/* aply format */
	return (sbuffer);
}

/**
 * process_char - process the c format identifier
 * and copy it in secondary buffer
 *
 * @sbuffer: buffer to be filled with arg
 * @format: format to be aplied in buffer before return it.
 * @param_list: list of arguments
 *
 * Return: pointer to secondary buffer.
 */
char *process_char(char *sbuffer, char *format, va_list param_list)
{
	char s = va_arg(param_list, int);

	if (!s)
		s = 1;
	_strncat(sbuffer, &s, 1);
	format[0] = '\0';
	/* aply format */

	return (sbuffer);
}

/**
 * process_int - copies the number in a secondary buffer.
 *
 * @sbuffer: pointer to string.
 * @format: format of the string.
 * @param_list: list of parameters entering variadic.
 *
 * Return: pointer to secondary buffer.
 */
char *process_int(char *sbuffer, char *format, va_list param_list)
{
	int number = va_arg(param_list, int);

	if (number < 0)
		sbuffer[0] = '-';
	format[0] = '\0';
	dec_converter(number, sbuffer, 10);

	return (sbuffer);
}


/**
 * process_binary - copies binary number into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_binary(char *sbuffer, char *format, va_list param_list)
{
	unsigned int number = va_arg(param_list, unsigned int);

	format[0] = '\0';
	dec_converter_uns(number, sbuffer, 2);

	return (sbuffer);
}

/**
 * process_custom_string - copies string into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list:parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_custom_string(char *sbuffer, char *format, va_list param_list)
{
	/* to do: when char i > 127, convert to in -*/
	int i_tmpBuf, i_sbuf = 0;
	char *tmpBuf = va_arg(param_list, char *);
	char tmpChar;
	char str_hex[20] = {0};	/* aply format next */

	format[0] = '\0';
	for (i_tmpBuf = 0; tmpBuf[i_tmpBuf]; i_tmpBuf++)
	{
		tmpChar = tmpBuf[i_tmpBuf];
		if ((0 < tmpChar && 32 > tmpChar) || tmpChar >= 127)
		{
			sbuffer[i_sbuf++] = '\\';
			sbuffer[i_sbuf++] = 'x';
			dec_converter(tmpChar, str_hex, 16);
			string_toupper(str_hex);
			if (tmpChar < 16)
			{
				sbuffer[i_sbuf++] = '0';
				sbuffer[i_sbuf++] = str_hex[0];
			}
			else
			{
				sbuffer[i_sbuf++] = str_hex[0];
				sbuffer[i_sbuf++] = str_hex[1];
			}
		}
		else
		{
			sbuffer[i_sbuf++] = tmpChar;
		}
	}
	sbuffer[i_sbuf] = '\0';
	return (sbuffer);
}

#include "holberton.h"

/**
 * copy_binary - copies binary number into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *copy_binary(char *sbuffer, char *format, va_list param_list)
{
	unsigned int number = va_arg(param_list, unsigned int);

	format[0] = '\0';
	dec_converter_uns(number, sbuffer, 2);

	return (sbuffer);
}

/**
 * copy_float - copies float number into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *copy_float(char *sbuffer, char *format, va_list param_list)
{
	format[0] = '\0';
	sbuffer[0] = va_arg(param_list, int);
	return (sbuffer);
}

/**
 * copy_custom_string - copies string into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list:parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *copy_custom_string(char *sbuffer, char *format, va_list param_list)
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

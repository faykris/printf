#include "holberton.h"

char *copy_binary(char *sbuffer, char *format, va_list param_list)
{
	int number= (int) va_arg(param_list, unsigned int);

	dec_converter(number, sbuffer, 2);

	return (sbuffer);
}
char *copy_float(char *sbuffer, char *format, va_list param_list)
{

}

char *copy_custom_string(char *sbuffer, char *format, va_list param_list)
{
	/**
	 * to do: when char i > 127, convert to in -
	 * 
	 */
	int i_tmpBuf, i_sbuf = 0;
	char *tmpBuf = va_arg(param_list, char *);
	char tmpChar;
	char str_hex[20] = {0};
	/* aply format */

	for (i_tmpBuf = 0; tmpBuf[i_tmpBuf]; i_tmpBuf++)
	{
		tmpChar = tmpBuf[i_tmpBuf];

		if ((0 < tmpChar && tmpChar < 32) || tmpChar >= 127)
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

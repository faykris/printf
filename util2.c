#include "holberton.h"

/**
 * dec_converter - changes to string a number.
 * @str_converted: secondary buffer to add numbers.
 * @dec: number to convert to string.
 * @base: base to convert number
 *
 * Return: None.
 */
void dec_converter(int dec, char *str_converted, int base)
{
	int index = 0;
	int cociente = dec;
	char letters[] = {"0123456789abcdef"};
	int inNegative = 0;

	if (cociente == 0)
		str_converted[index++] = '0';

	if (str_converted[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			str_converted[index++] = letters[-(cociente % base)];
		else
			str_converted[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		str_converted[index++] = '-';

	str_converted[index] = '\0';
	rev_string(str_converted);
}


/**
 * dec_converter_uns - changes to string an unsigned number.
 * @str_converted: secondary buffer to add numbers.
 * @dec: number to convert to string.
 * @base: base to convert number.
 *
 * Return: None.
 */
void dec_converter_uns(unsigned int dec, char *str_converted, int base)
{
	int index = 0;
	unsigned int cociente = dec;
	char letters[] = {"0123456789abcdef"};
	int inNegative = 0;

	if (cociente == 0)
		str_converted[index++] = '0';

	if (str_converted[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		str_converted[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		str_converted[index++] = '-';

	str_converted[index] = '\0';
	rev_string(str_converted);
}


/**
 * translate_format - changes to string an unsigned number.
 *
 * @buffer: pointer to response string
 * @format_buffer: pointer to format buffer
 *
 * Return: None.
 */
void translate_format(char *buffer, char *format_buffer)
{
	_strncat(buffer, "%", 1024);
	if (format_buffer[1] == '1')
		_strncat(buffer, "+", 1024);
	else if (format_buffer[2] == '1')
		_strncat(buffer, " ", 1024);
	if (format_buffer[0] == '1')
		_strncat(buffer, "-", 1024);
	else if (format_buffer[3] == '1')
		_strncat(buffer, "0", 1024);
	_strncat(buffer, format_buffer + 4, 1024);
}

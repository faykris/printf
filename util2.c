#include "holberton.h"

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

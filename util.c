#include "holberton.h"

/**
 * _strlen - returns the length of a string.
 *
 * @string: pointer to string.
 * Return: length of string.
 */
int _strlen(char *string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strncat - concatenates two strings.
 *
 * @dest: string to be modified.
 * @src: string to be copied to the end of dest.
 * @n: numbers of chars to be copied from src to dest.
 *
 * Return: pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_index = 0;
	int src_index = 0;

	while (*(dest + dest_index) != '\0')
		dest_index++;

	while (*(src + src_index) != '\0' && src_index < n)
	{
		*(dest + dest_index) = *(src + src_index);
		dest_index++;
		src_index++;
	}

	*(dest + dest_index) = '\0';

	return (dest);

}

/**
 * string_toupper - anges all lowercase letters of a string to uppercase.
 *
 * @str: pointer to array of chars.
 *
 * Return: pointer to *.
 */
void string_toupper(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
			*(str + i) += ('A' - 'a');
		i++;
	}
}

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
 * rev_string - reverses a string.
 *
 * @s: pointer to string.
 * Return: void.
 */
void rev_string(char *s)
{

	int len = _strlen(s);
	int index = 0;
	char hold;

	len--;
	if (s[0] == '-')
		index = 1;

	while (index < len)
	{
		hold = s[index];
		s[index] = s[len];
		s[len] = hold;

		index++;
		len--;
	}
}

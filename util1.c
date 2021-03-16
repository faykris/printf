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
 * _strncat - concatenates two strings and reallocates if needed.
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
	int src_index = 0, difference = 0;

	if ((_strlen(dest) + _strlen(src)) > 1023)
	{
		difference = 1023 - (_strlen(dest) + _strlen(src));
		dest = realloc(dest, 1024 + difference);
		if (dest == NULL)
		{
			exit(98);
		}
	}
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

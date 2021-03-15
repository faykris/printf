#include "holberton.h"

/**
 * _write - writes the characters to stdout.
 * @buffer: The string to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write(char *buffer)
{
	int bytes_printed = write(1, buffer, _strlen(buffer));

	free(buffer);
	buffer = "";
	return (bytes_printed);
}

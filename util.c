#include "holberton.h"


/**
 * select_func -
 *
 * @specifier: pointer to string.
 *
 * Return: pointer tocopy_function selected
 */
char *(*select_func(char specifier))(char *, char *, va_list)
{
	copy_func array_copy_func[] = {
		{'s', copy_string},
		{'c', copy_char},
		{'d', copy_int},
		{'i', copy_int},
		{'f', copy_float}
	};

	int index = 0;

	while (specifier != array_copy_func[index].esp)
	{
		index++;
	}
	return (array_copy_func[index].ptr_func);
}


/**
 * clean_format -
 *
 * @specifier: pointer to string.
 *
 * Return: pointer tocopy_function selected
 */
char *clean_format(char *ptr_to_percent, char *buffer_format, int index_spc)
{
	int index, index_buffer = 4, id_sec = 0, has_point = 0;

	buffer_format[0] = buffer_format[1] = '0';
	buffer_format[2] = buffer_format[3] = '0';

	for (index = 1; index < index_spc; index++)
	{
		switch (ptr_to_percent[index])
		{
			case '-':
				if (id_sec)
					return (NULL);
				buffer_format[0] = '1';
				break;
			case '+':
				if (id_sec)
					return (NULL);
				buffer_format[1] = '1';
				break;
			case ' ':
				if (id_sec)
					return (NULL);
				buffer_format[2] = '1';
				break;
			case '.':
				if (has_point)
					return (NULL);
				buffer_format[index_buffer++] = '.';
				id_sec = 1;
				has_point = 1;
				break;
			case '0':
				if (id_sec)
					buffer_format[index_buffer++] = '0';
				else
					buffer_format[3] = '1';
				break;
			default:
				if ('0' < ptr_to_percent[index] && ptr_to_percent[index] <= '9')
				{
					id_sec = 1;
					buffer_format[index_buffer++] = ptr_to_percent[index];
				}
				else
					return (NULL);
		}
	}
	buffer_format[index_buffer]= '\0';
	return (buffer_format);
}

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
 * int_to_str - changes to string a number.
 * @sbuffer: secondary buffer to add numbers.
 * @number: number to convert to string.
 *
 * Return: None.
 */
void int_to_str(char *sbuffer, int number)
{
        int copy_number = number;
        int index, length, magnitud = 1;

	for (length = 0; (copy_number / 10) == 0; length++)
	{
		copy_number / 10;
		magnitud * 10;		
	}
	length++;
	for (index = 0; index < length; index++)
	{
		sbuffer[index] = (char)(number / magnitud);
		number = number % magnitud;
		magnitud / 10;
	}
}

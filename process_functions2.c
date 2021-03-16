#include "holberton.h"

/**
 * process_hex - copies hex number into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_hex(char *sbuffer, char *format, va_list param_list)
{
	int len_format = _strlen(format);
	unsigned int argument = va_arg(param_list, unsigned int);

	dec_converter(argument, sbuffer, 16);

	if (format[len_format - 1] == 'X')
		string_toupper(sbuffer);

	format[0] = '\0';
	return (sbuffer);
}

/**
 * process_float - copies float number into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_float(char *sbuffer, char *format, va_list param_list)
{
	format[0] = '\0';
	sbuffer[0] = va_arg(param_list, int);
	return (sbuffer);
}

/**
 * process_pointer - copies pointer address into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_pointer(char *sbuffer, char *format, va_list param_list)
{
	unsigned long argument = va_arg(param_list, unsigned long);

	if (argument == 0)
		_strncat(sbuffer, "(nil)", 1024);
	else
	{
		dec_converter_uns(argument, sbuffer, 16);
		rev_string(sbuffer);
		_strncat(sbuffer, "x0", 1024);
		rev_string(sbuffer);
	}
	format[0] = '\0';

	return (sbuffer);
}

/**
 * process_uns_int - copies unsigned integer into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_uns_int(char *sbuffer, char *format, va_list param_list)
{
	unsigned int number = va_arg(param_list, unsigned int);

	format[0] = '\0';
	/* apply format */

	dec_converter_uns(number, sbuffer, 10);

	return (sbuffer);
}

/**
 * process_octal - copies octal of integer into the secondary buffer.
 * @sbuffer: empty secondary buffer to copy data.
 * @format: pointer with the format that the data needs.
 * @param_list: parameters not declared in variadic function.
 *
 * Return: secondary buffer changed.
 */
char *process_octal(char *sbuffer, char *format, va_list param_list)
{
	unsigned int number = va_arg(param_list, unsigned int);

	format[0] = '\0';
	/* apply format */

	dec_converter_uns(number, sbuffer, 8);

	return (sbuffer);
}
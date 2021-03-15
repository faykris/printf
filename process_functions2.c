#include "holberton.h"


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


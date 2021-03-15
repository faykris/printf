#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int steps(char *ptr_to_percent, va_list param_list, char *buffer);

char *(*select_func(char specifier))(char *, char *, va_list);

char *clean_format(char *ptr_to_percent, char *buffer_format, int index_spc);

void string_copy(char *, char *, char, va_list);

int _write(char *buffer);

int _strlen(char *string);

void string_toupper(char *str);

void dec_converter(int dec, char *str_converted, int base);

char *_strncat(char *, char *, int n);

void rev_string(char *s);

char *copy_string(char *sbuffer, char *format, va_list param_list);

char *copy_char(char *sbuffer, char *format, va_list param_list);

char *copy_int(char *sbuffer, char *format, va_list param_list);

char *copy_binary(char *sbuffer, char *format, va_list param_list);

char *copy_float(char *sbuffer, char *format, va_list param_list);

char *copy_custom_string(char *sbuffer, char *format, va_list param_list);

void int_to_str(char *sbuffer, int number);

/**
 * struct cp_func - structure holds data type and pointer.
 * @esp: especial character (s, f, i, d, ...).
 * @ptr_func: pointer to function with two pointers and va_list as paramenter.
 *
 * Description: structure that contains in the first position the char especial
 * and in the second one the pointer that manipulates that type of char.
 */
struct cp_func
{
	char esp;
	char *(*ptr_func)(char *sbuffer, char *format, va_list param_list);
};

typedef struct cp_func copy_func;

#endif /* HOLBERTON_H */

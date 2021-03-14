#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format,...);

int steps(char *ptr_to_percent, va_list param_list, char *buffer);

char *(*select_func(char specifier))(char *, char *, va_list );

char *clean_format(char *ptr_to_percent, char *buffer_format, int index_spc);

void string_copy(char *buffer, char *format_buffer, char specifier, va_list param_list);

int _write(char *buffer);

int _strlen(char *string);

void dec_to_hex(int dec, char *str_hex, int toMayus);

char *_strncat(char *, char *, int n);

void rev_string(char *s);

char *copy_string(char *sbuffer, char *format, va_list param_list);

char *copy_char(char *sbuffer, char *format, va_list param_list);

char *copy_int(char *sbuffer, char *format, va_list param_list);

char *copy_binary(char *sbuffer, char *format, va_list param_list);

char *copy_float(char *sbuffer, char *format, va_list param_list);

char *copy_custom_string(char *sbuffer, char *format, va_list param_list);

/**
 * cp_func - 
 *
 * @esp: 
 * @ptr_func: 
 */
struct cp_func
{
	char esp;
	char *(*ptr_func)(char *sbuffer, char *format, va_list param_list);
};

typedef struct cp_func copy_func;


#endif /* HOLBERTON_H */

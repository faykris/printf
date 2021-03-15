#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

/* printf.c */
int _printf(const char *format, ...);

int find_format(char *ptr_to_percent, va_list param_list, char *buffer);

/* core.c*/
void append_arg(char *, char *, char, va_list);

char *get_format(char *ptr_to_percent, char *buffer_format, int index_spc);

char *(*select_func(char specifier))(char *, char *, va_list);

int _write(char *buffer);

/* util1.c*/

int _strlen(char *string);

void string_toupper(char *str);

char *_strncat(char *, char *, int n);

void rev_string(char *s);

/* util2.c */
void dec_converter(int dec, char *str_converted, int base);

void dec_converter_uns(unsigned int dec, char *str_converted, int base);

/* process_functions1.c*/
char *process_string(char *sbuffer, char *format, va_list param_list);

char *process_char(char *sbuffer, char *format, va_list param_list);

char *process_int(char *sbuffer, char *format, va_list param_list);

char *process_binary(char *sbuffer, char *format, va_list param_list);

char *process_custom_string(char *sbuffer, char *format, va_list param_list);

/* process_functions2.c*/

char *process_uns_int(char *sbuffer, char *format, va_list param_list);

char *process_octal(char *sbuffer, char *format, va_list param_list);

char *process_hex(char *sbuffer, char *format, va_list param_list);

char *process_float(char *sbuffer, char *format, va_list param_list);

char *process_pointer(char *sbuffer, char *format, va_list param_list);

/* process_functions3.c*/

char *process_reverse(char *sbuffer, char *format, va_list param_list);

char *process_root13(char *sbuffer, char *format, va_list param_list);


/**
 * struct cp_func - structure holds data type and pointer.
 * @esp: especial character (s, f, i, d, ...).
 * @ptr_func: pointer to function with pair pointers and va_list as paramenter.
 *
 * Description: structure that contains in the first position the char especial
 * and in the second one the pointer that manipulates that type of char.
 */
struct cp_func
{
	char esp;
	char *(*ptr_func)(char *sbuffer, char *format, va_list param_list);
};

typedef struct cp_func process_func;

#endif /* HOLBERTON_H */

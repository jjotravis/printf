#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);

/**
 * struct type_struct - specifier struct
 * @c: specifier
 * @func: pointer to spec func
 */
typedef struct type_struct
{
	char c;
	int (*func)(va_list);
} spec_func;

int (*comp_func(const char d))(va_list);
int printc(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_heX(va_list args);
int print_unsigned(va_list args);
int base_len(size_t number, int base);
int hex_check(int num, char c);
int get_num_len(size_t num);
int print_reverse(va_list args);

#endif

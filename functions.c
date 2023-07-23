#include "main.h"

/**
 * printc - print character
 * @args: va_list args
 * Return: char count
 */

int printc(va_list args)
{
	char letter;

	letter = (char) va_arg(args, int);
	return (write(1, &letter, 1));
}

/**
 * print_string - print string
 * @args: va_list args
 * Return: char count
 */

int print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	return (write(1, str, strlen(str)));
}

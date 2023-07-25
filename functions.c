#include "main.h"
#include <stdio.h>

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

/**
 * print_int- print integer base 10
 * @args: va_list args
 * Return: char count
 */

int print_int(va_list args)
{
	long num;
	int count, primary_digit, base, temp;

	count = 0;
	num = va_arg(args, int);

	if (num < 0)
	{
		temp = 45;
		num *= -1;
		write(1, &temp, 1);
		count++;
	}
	if (num >= 0 && num <= 9)
	{
		temp = num + 48;
		write(1, &temp, 1);
		count++;
	}
	if (num > 9)
	{
		base = 10;

		while (num / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			primary_digit = num / base;
			num = num % base;
			temp = primary_digit + 48;
			write(1, &temp, 1);
			base = base / 10;
			count++;
		}
	}
	return (count);
}

/**
 * get_num_len - get the len of the number passed
 * @number: number
 * Return: len of the number
 */
int get_num_len(size_t num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);

	while (num > 0)
	{
		len = len + 1;
		num = num / 10;
	}
	return (len);
}

/**
 * print_unsigned - print usigned integers
 * @args: argument list
 * Return: char printed
 */
int print_unsigned(va_list args)
{
	size_t num;
	int len, idx, count, i;
	char *str_ptr;

	count = 0;
	num = va_arg(args, size_t);
	len = get_num_len(num);

	str_ptr = malloc(sizeof(char) * len + 1);
	if (str_ptr == NULL)
		return (-1);
	
	idx = len - 1;
	while (num > 0)
	{
		str_ptr[idx] = '0' + (num % 10);
		num = num / 10;
		idx--;
	}

	for (i = 0; i < len; i++)
	{
		write(1, &str_ptr[i], 1);
		count++;
	}
    free(str_ptr);
	return (count);
}

/**
 * base_len - return the character len of converted integer
 * @number: number to be convert
 * @base: base to be converted to
 * Return: char count
 */
int base_len(size_t number, int base)
{
	size_t i;

	for (i = 0; number > 0; i++)
		number = number / base;
	return (i);
}



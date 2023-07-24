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

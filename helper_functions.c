#include "main.h"

/**
 * hex_check - check if hex values are upper | lower case
 * @c: char to tell which hex is called
 * @num: number to convert ot letter
 * Return: ascii value of a letter
 */
int hex_check(int num, char c)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (c == 'x')
	{
		return (hex[num]);
	}
	else
	{
		return (Hex[num]);
	}

	return (0);
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

/**
 * get_num_len - get the len of the number passed
 * @num: number passed
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

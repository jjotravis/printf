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

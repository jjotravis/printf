#include "main.h"

/**
 * print_binary- print integer as binary
 * @args: va_list args
 * Return: char count
 */
int print_binary(va_list args)
{
	int i, j, len;
	size_t num;
	char *str;

	num = va_arg(args, size_t);

	if (num == 0)
		return (write(1, "0", 1));

	if (num < 1)
		return (-1);

	/* return the length of the binary */
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);

	i = 0;
	while (num > 0)
	{
		str[i] = '0' + (num % 2);
		num = num / 2;
		i++;
	}
	str[i] = '\0';

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	free(str);
	return (len);
}

/**
 * print_octal - print integer as octal
 * @args: va_list args
 * Return: char count
 */
int print_octal(va_list args)
{
	int i, j, len;
	size_t num;
	char *str;

	num = va_arg(args, size_t);

	if (num == 0)
		return (write(1, "0", 1));

	if (num < 1)
		return (-1);

	/* return the length of the binary */
	len = base_len(num, 8);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);

	i = 0;
	while (num > 0)
	{
		str[i] = (num % 8) + 48;
		num = num / 8;
		i++;
	}
	str[i] = '\0';

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	free(str);
	return (len);
}

/**
 * print_hex- print integer as hex
 * @args: va_list args
 * Return: char count
 */
int print_hex(va_list args)
{
	int i, j, len, remainder;
	size_t quotient;
	char *str;


	quotient = va_arg(args, size_t);

	if (quotient == 0)
		return (write(1, "0", 1));

	if (quotient < 1)
		return (-1);

	/* return the length of the binary */
	len = base_len(quotient, 16);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);

	i = 0;
	while (quotient > 0)
	{
		remainder = quotient % 16;
		if (remainder > 9)
		{
			remainder = hex_check(remainder, 'x');
			str[i++] = remainder;
		}
		else
		{
			str[i++] = remainder + 48;
		}

		quotient = quotient / 16;
	}
	str[i] = '\0';

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	free(str);
	return (len);
}

/**
 * print_heX- print integer as heX
 * @args: va_list args
 * Return: char count
 */
int print_heX(va_list args)
{
	int i, j, len, remainder;
	size_t quotient;
	char *str;


	quotient = va_arg(args, size_t);

	if (quotient == 0)
		return (write(1, "0", 1));

	if (quotient < 1)
		return (-1);

	/* return the length of the binary */
	len = base_len(quotient, 16);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);

	i = 0;
	while (quotient > 0)
	{
		remainder = quotient % 16;
		if (remainder > 9)
		{
			remainder = hex_check(remainder, 'X');
			str[i++] = remainder;
		}
		else
		{
			str[i++] = remainder + 48;
		}

		quotient = quotient / 16;
	}
	str[i] = '\0';

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	free(str);
	return (len);
}

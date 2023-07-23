#include "main.h"

/**
*_printf - Print output according to format
*@format: Format specifier
*Return: 0 on success
*/

int _printf(const char *format, ...)
{
	va_list args;
	char c;
	char *str;
	int count;

	va_start(args, format);
	count = 0;
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args,  char *);
					write(1, str, strlen(str));
					count += strlen(str);
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}

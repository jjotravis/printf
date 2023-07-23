#include "main.h"

/**
*_printf - Print output according to format
*@format: Format specifier
*Return: 0 on success
*/

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}

		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					char c = (char)va_arg(args, int);

					write(1, &c, 1);
					break;

				case 's':
					char *str = va_arg(args,  char *);

					write(1, str, strlen(str));
					break;

				case '%':
					char s = (char)va_arg(args, int);

					write(1, "%", 1);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (0);
}

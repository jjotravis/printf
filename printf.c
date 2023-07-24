#include "main.h"

/**
*_printf - Print output according to format
*@format: Format specifier
*Return: 0 on success
*/
int _printf(const char *format, ...)
{
	va_list args;
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
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += comp_func(*format)(args);
					break;
				case 's':
					count += comp_func(*format)(args);
					break;
				case 'd': case 'i':
					count += comp_func(*format)(args);
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				case '\0':
					return (-1);
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * comp_func - calls function for the passed specifier
 * @d: specifier passed
 * Return: pointer to specifier function
 */
int (*comp_func(const char d))(va_list)
{
	int i;
	spec_func print_func[] = {
		{'c', printc},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int}
	};

	for (i = 0; print_func[i].c != '\0'; i++)
	{
		if (print_func[i].c == d)
			return (print_func[i].func);
	}

	return (0);
}

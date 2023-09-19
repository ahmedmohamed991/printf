#include "main.h"

/**
 * _precision - calculate the precision
 * @format: formatted string in which to print the arg
 * @a: list of argument to be printed
 * @l: list of argument
 *
 * Return: precision
 */

int _precision(const char *format, int *a, va_list l)
{
	int y = *a + 1, p = -1;

	if (format[y] != '.')
		return (p);

	p = 0;

	for (y += 1; format[y] != '\0'; y++)
	{
		if (_digit(format[y]))
		{
			p *= 10;
			p += format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			p = va_arg(l, int);
			break;
		}
		else
			break;
	}
	*a = y - 1;

	return (p);
}

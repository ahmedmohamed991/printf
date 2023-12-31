#include "main.h"
/**
 * _width - compute the width for printing
 * @format: format string in which to print the arguments
 * @a: list of arguments to be printed
 * @l: list of arguments
 * Return: width
 */
int _width(const char *format, int *a, va_list l)
{
	int w = 0;
	int y;

	for (y = *a + 1; format[y] != '\0'; y++)
	{
		if (_digit(format[y]))
		{
			w *= 10;
			w += format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			w = va_arg(l, int);
			break;
		}
		else
			break;
		}

	*a = y - 1;
	return (w);
}

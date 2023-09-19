#include "main.h"

/**
 * get_precision - calculate the precision
 * @format: formatted string in which to print the arg
 * @x: list of argument to be printed
 * @num: list of argument
 *
 * Return: precision
 */

int get_precision(const char *format, int *x, va_list num)
{
	int y = *x + 1, precision = -1;

	if (format[y] != '.')
		return (precision);

	precision = 0;

	for (y += 1; format[y] != '\0'; y++)
	{
		if (is_digit(format[y]))
		{
			precision *= 10;
			precision += format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			precision = va_arg(num, int);
			break;
		}
		else
			break;
	}
	*x = y - 1;

	return (precision);
}

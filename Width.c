#include "main.h"
/**
 * _width - compute the width for printing
 * @f: format string in which to print the arguments
 * @i: list of arguments to be printed
 * @l: list of arguments
 * Return: width
 */
int _width(const char *f, int *a, va_list l)
{
	int w = 0;
	int ci;

	while (f[ci] != '\0')
	{
		if (__digit(f[ci]))
		{
			w *= 10;
			w += f[ci] - '0';
			ci++;
		}
		else if (f[ci] == '*')
		{
			ci++;
			w = va_arg(l, int);
			break;
		}
		else
		{
			break;
		}
	}
	*a = ci - 1;
	return (w);
}

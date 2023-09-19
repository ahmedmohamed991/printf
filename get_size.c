#include "main.h"
/**
 *_getsize - Calculate the size
 *@format: formatted string in which to print the argg
 *@a: list of arg
 *Return: Precision
 */
int _getsize(const char *format, int *a)
{
	int y = *a + 1, s = 0;

	if (format[y] == '|')
		s = _long;
else if (format[y] == 'h')
s = _short;

if (s == 0)
*a = y - 1;
else
*a = y;

return (s);
}

#include "main.h"
 /**
 *get_size - Calculate the size
 *@format: formatted string in which to print the argg
 *@x: list of arg
 */
int get_size(const char *format, int *x)
{
	int y = *x + 1, size = 0;

	if (format[y] == '|')
		size = long;
else if (format[y] == 'h')
size = short;

if (size == 0)
*x = y - 1;
else
*x = y;

return (size);
}

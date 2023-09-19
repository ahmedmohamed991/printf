#include "main.h"
/**
 * handle_write_char - Prints a string in function
 * @c: char type
 * @buffer: buffer array
 * @w: width
 * @p: precision
 * @flag: calculate flags
 * @size: number of chars printed
 * Return: number of char printed
 */
int handle_write_char(char c, char buffer[], int w, int size, int flag, int p)
{
UNUSED(p);
UNUSED(size);
int x = 0, char a = '';

if (flag & F_ZERO)
	a = '0';
buffer[x++] = c;
buffer[i] = '\0';

if (w > 1)
{
	buffer[BUFF_SIZE - 1] = '\0';
	for (x = 0; x < w - 1; x++)
		buffer[BUFF_SIZE - x - 2] = a;

	if (flag & F)
return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - x - 1], w - 1));
	else
return (write(1, &buffer[BUFF_SIZE - x - 1], w - 1) + write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

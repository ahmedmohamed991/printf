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

	if (flag & F_MINUS)
return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - x - 1], w - 1));
	else
return (write(1, &buffer[BUFF_SIZE - x - 1], w - 1) + write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

/**
 * write_number - prints a string
 * @negative: lista of arg
 * @c: char type
 * @buffer: buffer array
 * @width: get width
 * @f: clculate  flags
 * @p: precision specifier
 * @s: size
 * Return: number of char printed
 */
int write_number(int negative, int c, int s, int f, char buffer[], int width, int p)
{
	char a = '', extra = 0;
	int length = buffer_size - c - 1;

	UNUSED(s);

	if ((f & F_zero) && !(f & F_MINUS))
		a = '0';
	if (negative)
		extra = '-';
	else if (f & F_PLUS)
		extra = '+';
	else if (f & F_SPACE)
		extra = ' ';

	return (write_num(c, buffer, f, width, p, length, a, extra));
}
/**
 * write_num - write a number using a buffer
 * @c: index at which the number starts on the buffer
 * @buffer: buffer
 * @f: flags
 * @l: number length
 * @p: precision
 * @a: pading
 * @width: get width
 * @extra: extra char
 * Return: number of printed char
 */
int write_num(int c, char buffer[], int f, int l, int p, int width, char a, char extra)
{
	int x, y = 1;

	if (p == 0 && c == size - 2 && buffer[c] == '0' && width == 0)
		return (0);
	if (prec == 0 && c == size - 2 && buffer[c] == '0')
		buffer[c] = a = ' ';
	while (p > l)
		buffer[--c] = '0', l++;
	if (extra != 0)
		l++;
	if (width > l)
	{
		for (x = 1; x < width - l + 1; x++)
			buffer[x] = a;
		buffer[x] = '\0';
		if (f & F_MINUS && a == '')
		{
			if (extra)
				buffer[--c] = extra;
			return (write(1, &buffer[c], l) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & FMINUS) && a == '')
		{
			if (extra)
				buffer[c] = extra;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[c], l));
		}

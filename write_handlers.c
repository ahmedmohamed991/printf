#include "main.h"
/**
 * _writechar - Prints a string in function
 * @c: char type
 * @b: buffer array
 * @w: width
 * @p: precision
 * @f: calculate flags
 * @s: number of chars printed
 * Return: number of char printed
 */
int _writechar(char c, char b[], int f, int w, int p, int s)
{

	int a = 0, char pa = ' ';

UNUSED(p);
UNUSED(s);


if (f & fzero)
	pa = '0';
b[a++] = c;
b[a] = '\0';

if (w > 1)
{
	b[buff - 1] = '\0';
	for (a = 0; a < w - 1; a++)
		b[buff - a - 2] = pa;

	if (f & fminus)
return (write(1, &b[0], 1) + write(1, &b[buff - a - 1], w - 1));
	else
	return (write(1, &b[buff - a - 1], w - 1) + write(1, &b[0], 1));
}
return (write(1, &b[0], 1));
}

/**
 * _numbers - prints a string
 * @_negative: lista of arg
 * @d: char type
 * @b: buffer array
 * @w: get width
 * @f: clculate  flags
 * @p: precision specifier
 * @s: size
 * Return: number of char printed
 */
int _numbers(int _negative, int d, char b[], int f, int w, int p, int s)
{
	char pa = ' ', ec = 0;
	int l = buff - c - 1;

	UNUSED(s);

	if ((f & fzero) && !(f & fminus))
		pa = '0';
	if (_negative)
		ec = '-';
	else if (f & fplus)
		ec = '+';
	else if (f & fspace)
		ec = ' ';

	return (_num(c, b, f, w, p, l, pa, ec));
}
/**
 * _num - write a number using a buffer
 * @d: index at which the number starts on the buffer
 * @b: buffer
 * @f: flags
 * @l: number length
 * @p: precision
 * @pa: pading
 * @w: get width
 * @ec: extra char
 * Return: number of printed char
 */
int _num(int d, char b[], int f, int l, int p, int w, char pa, char ec)
{
	int a, ps = 1;

	if (p == 0 && d == buff - 2 && b[d] == '0' && w == 0)
		return (0);
	if (p == 0 && d == buff - 2 && b[d] == '0')
		b[d] = pa = ' ';
	while (p > l)
		b[--d] = '0', l++;
	if (ec != 0)
		l++;
	if (w > l)
	{
		for (a = 1; a < w - l + 1; a++)
			b[a] = pa;
		b[a] = '\0';
		if (f & fminus && pa == ' ')
		{
			if (ec)
				b[--d] = ec;
			return (write(1, &b[d], l) + write(1, &b[1], x - 1));
		}
		else if (!(f & fminus) && pa == ' ')
		{
			if (ec)
				b[d] = ec;
			return (write(1, &b[1], x - 1) + write(1, &b[d], l));
		}
/**
 * _unsgnd - writes an unsigned num
 * @_negative: number indicating
 * @d: index at which the number starts in buffer
 * @b: Array of char
 * @f: flags
 * @w: width specifier
 * @s: size
 * @p: precision
 * Return: number of written chars
 */
int _unsgnd(int _negative, int d, char b[],
		int f, int w, int p, int s)
{
	char pa = ' ';
	int a = 0, l = buff - d - 1;

	UNUSED(_negative);
	UNUSED(s);
		if (p == 0 && d == buff - s && b[d] == '0')
			return (0);
	if (p > 0 && p < l)
		pa = ' ';
	while (p > l)
	{
		b[--d] = '0';
		l++;
	}
	if ((f & fzero) && !(f & fminus))
		pa = '0';
	if (w > l)
	{
		for (a = 0; a < w - l ; a++)
			b[a] = pa;
		b[a] = '\0';
		if (f & fminus)
		{
			return (write(1, &b[d], l) + write(1, &b[0], a));
			else
			{
				return (write(1, &b[0], a) + write(1, &b[d], l));
			}}
		return (write(1, &b[d], l));
	}

/**
 * write_pointer - write a memory address
 *@b: arrayes
 * @d: the number starts in thhe buffer index
 * @l: length
 * @w: width specifire
 * @f: flags
 * @pa: char padding
 * @ec: extra
 * @ps: index at which padding start
 * Return: number of written
 */
int write_pointer(char b[], int d, int l, int w,
int f, char pa, char ec, int ps)
{
	int a;

	if (w > l)
	{
		for (a = 3; a < w - l + 3; a++)
			b[a] = pa;
		b[a] = '\0';
		if (f & fminus && pa == ' ')
		{
			b[--d] = 'x';
			b[--d] = '0';
			if (ec)
				b[--d] = ec;
			return (write(1, &b[d], l) + write(1, &b[3], a - 3));
		}
		else if (!(f &fminus) && pa == ' ')
		{
			b[--d] = 'x';
			b[--d] = '0';
			if (ec)
				b[--d] = ec;
			return (write(1, &b[3], a - 3) + write(1, &b[d], l));
		}
		else if (!(f & fminus) && pa == '0')
		{
			if (ec)
				b[--ps] = ec;
			b[1] = '0';
			b[2] = 'x';
			return (write(1, &b[ps], a - ps) + write(1, &b[d], l - (1 - ps) - 2));
		}
	}
	b[--d] = 'x';
	b[--d] = '0';
	if (ed)
		b[--d] = ec;
	return (write(1, &b[d], buff - d - 1));
}

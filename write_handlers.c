#include "main.h"
/**
 * _writechar - prints a string
 * @c: char type
 * @b: buffer array
 * @f: calculates active flags
 * @w: width
 * @p: precision specifier
 * @s: size
 * Return: number of chars printed
 */
int _writechar(char c, char b[], int f
		, int w, int p, int s)
{
	int a = 0;
	int pa = ' ';

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
 * @_negative: lista of arguments
 * @d: char type
 * @b: buffer array
 * @f: clculates flag
 * @w: width
 * @p: precision
 * @s: size
 * Return: number of chars printed
 */
int _numbers(int _negative, int d, char b[],
int f, int w, int p, int s)
{
	int l = buff - d - 1;
	char pa = ' ', ec = 0;

	UNUSED(s);

	if ((f & fzero) && !(f & fminus))
		pa = '0';
	if (_negative)
		ec = '-';
	else if (f & fplus)
		ec = '+';
	else if (f & fspace)
		ec = ' ';
	return (_num(d, b, f, w, p, l, pa, ec));
}
/**
 * _num - write a number using a buffer
 * @d: index at which the number starts on buffer
 * @b: buffer array
 * @f: flags
 * @w: width
 * @p: precision
 * @l: number length
 * @pa: pading char
 * @ec: extra char
 * Return: number of printed chars
 */
int _num(int d, char b[], int f, int w,
int p, int l, char pa, char ec)
{
	int a, ps = 1;

	if (p == 0 && d == buff - 2 && b[d] == '0' && w == 0)
		return (0);
	if (p == 0 && d == buff - 2 && b[d] == '0')
	pa = ' ';
		b[d] == pa;
	if (p > 0 && p < l)
		pa = ' ';
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
			return (write(1, &b[d], l) + write(1, &b[1], a - 1));
		}
		else if (!(f & fminus) && pa == ' ')
		{
			if (ec)
				b[--d] = ec;
			return (write(1, &b[1], a - 1) + write(1, &b[d], l));
		}
		else if (!(f & fminus) && pa == '0')
		{
			if (ec)
				b[--ps] = ec;
			return (write(1, &b[ps], a - ps) + write(1, &b[d], l - (1 - ps)));
		}
	}
	if (ec)
		b[--d] = ec;
	return (write(1, &b[d], l));
}
/**
 * _unsgnd - writes an unsigned number
 * @_negative: number indicating if the num is negative
 * @d: index at which the number starts in the buffer
 * @b: buffer array
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 * Return: number of written chars
 */
int _unsgnd(int _negative, int d, char b[],
		int f, int w, int p, int s)
{
	int l = buff - d - 1, a = 0;
	char pa = ' ';

	UNUSED(_negative);
	UNUSED(s);

	if (p == 0 && d == buff - 2 && b[d] == '0')
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
		for (a = 0; a < w - l; a++)
			b[a] = pa;
		b[a] = '\0';
		if (f & fminus)
		{
			return (write(1, &b[d], l) + write(1, &b[0], a));
		}
		else
		{
			return (write(1, &b[0], a) + write(1, &b[d], l));
		}
	}
	return (write(1, &b[d], l));
}
/**
 * write_pointer - write a memory address
 * @b: buffer array
 * @d: index
 * @l: length
 * @w: width
 * @f: flags
 * @pa: char representing the padding
 * @ec: extra char
 * @ps: index at which padding shoud start
 * Return: number of written chars
 */
int write_pointer(char b[], int d, int l,
		int w, int f, char pa, char ec, int ps)
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
		else if (!(f & fminus) && pa == ' ')
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
	if (ec)
		b[--d] = ec;
	return (write(1, &b[d], buff - d - 1));
}


#include "main.h"
/**
 * _char - Prints a char
 * @t: list of variables
 * @s: size
 * @b: array to handle print
 * @f: compute active flags
 * @w: width
 * @p: precision identification
 *Return: number of chars printed
 */
int _char(va_list t, char b[], int w, int f, int p, int s)
{
	char c;

	c = va_arg(t, int);
	return (_writechar(c, b, f, w, p, s));
}

/**
 * _string - prints a string
 * @t: list af variables
 * @b: array to handle print
 * @f: compute active flags
 * @w: width
 * @s: size
 * @p: precision
 * Return: number of chars printed
 */
int _string(va_list t, char b[], int f, int w, int s, int p)
{
	char *s = va_arg(t, char *);
	int l, a;

	l = 0;
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	if (s == NULL)
	{
		s = "(null)";
		if (p >= 6)
			s = " ";
	}
	while (s[l] != '\0')
		l++;
	if (p >= 0 && p < l)
		l = p;
	if (w > l)
	{
		switch (f & fminus)
		{
			case 0:
				for (a = w - l; a > 0; a--)
				{
					write(1, " ", 1);
				}
				write(1, &s[0], l);
				return (w);
			case fminus:
				write(1, &s[0], l);
				for (a = w - l; a > 0; a--)
				{
					write(1, " ", 1);
				}
				return (w);
		}
	}
	return (write(1, s, l));
}
/**
 * _percent - prints a percent sign
 * @t: list of arguments
 * @b: buffer array to handle
 * @f: computes active glags
 * @w: width
 * @p: precision
 * @s: Size
 * Return: number of chars printed
 */
int _percent(va_list t, char b[], int f, int w, int p, int s)
{
	UNUSED(t);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	return (write(1, "%%", 1));
}
/**
 * _int - print int
 * @t: list of variables
 * @s: size
 * @b: buffer array
 * @p: precision
 * @w: width
 * @f: flags
 * Return: number of chars printed
 */
int _int(va_list t, char b[], int f, int s, int w, int p)
{
	int a;
	int _negative;
	long int n;
	unsigned long int num;

	a = buff - 2;
	_negative = 0;
	n = va_arg(t, long int);

	n = _size(n, s);

	if (a == 0)
		b[a--] = '0';
	b[buff - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		_negative = 1;
	}

	while (num > 0)
	{
		b[a--] = (num % 10) + '0';
		num /= 10;
	}
	a++;
	return (_numbers(_negative, a, b, f, w, p, s));
}
/**
 * _binary - prints an unsigned number
 * @t: list of arguments
 * @b: buffer array
 * @s: size
 * @w: width
 * @f: flags
 * @p: precision
 * Return: number of chars printed
 */
int _binary(va_list t, char b[], int f, int w, int s, int p)
{
	unsigned int o[32];
	unsigned int a, q, n, sum;
	int c;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	n = va_arg(t, unsigned int);
	q = 2147483648; /* (2 ^ 31)*/
	o[0] = n / q;
	for (a = 1; a < 32; a++)
	{
		q /= 2;
		o[a] = (n / q) % 2;
	}
	for (a = 0, sum = 0, c = 0; a < 32; a++)
	{
		sum += o[a];
		if (sum || a == 31)
		{
			char r;

			r = '0' + o[a];
			write(1, &r, 1);
			c++;
		}
	}
	return (c);
}















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
	char k;

	k = va_arg(t, int);
	return (handle_write_char(k, b, f, w, p, s));
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
	int l, i;

	l = 0;
	unused(b);
	unused(f);
	unused(w);
	unused(p);
	unused(s);
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
				for (i = w - l; i > 0; i--)
				{
					write(1, " ", 1);
				}
				write(1, &s[0], l);
				return (w);
			case fminus:
				write(1, &s[0], l);
				for (i = w - l; i > 0; i--)
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
	unused(t);
	unused(b);
	unused(f);
	unused(w);
	unused(p);
	unused(s);
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
	int k;
	int negative;
	long int a;
	unsigned long int n;

	k = buff - 2;
	negative = 0;
	a = va_arg(t, long int);

	a = convert_size(a, s);

	if (a == 0)
		b[k--] = '0';
	b[buff - 1] = '\0';
	n = (unsigned long int)a;

	if (a < 0)
	{
		n = (unsigned long int)((-1) * a);
		negative = 1;
	}

	while (n > 0)
	{
		b[k--] = (n % 10) + '0';
		n /= 10;
	}
	k++;
	return (write_numbers(negative, k, b, f, w, p, s));
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
	unsigned int g, q, n, sum;
	int c;

	unused(b);
	unused(f);
	unused(w);
	unused(p);
	unused(s);

	n = va_arg(t, unsigned int);
	q = 2147483648; /* (2 ^ 31)*/
	o[0] = n / q;
	for (g = 1; g < 32; g++)
	{
		q /= 2;
		o[g] = (n / q) % 2;
	}
	for (g = 0, sum = 0, c = 0; g < 32; g++)
	{
		sum += o[g];
		if (sum || g == 31)
		{
			char r;

			r = '0' + o[g];
			write(1, &r, 1);
			c++;
		}
	}
	return (c);
}















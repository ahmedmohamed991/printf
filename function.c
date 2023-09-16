#include "main.h"
/**
 * _pointer - function that prints the value of a pointer
 * @t: list of arguments
 * @b: buffer array
 * @f: computes active flags
 * @w: width
 * @s: size
 * @p: precision
 * Return: number of chars printed
 */
int _pointer(va_list t, char b[], int f, int w, int s, int p)
{
	int d = buff - 2, l = 2, ps = 1; /*l = 2, for '0x'*/
	char ec = 0, pa = ' ';
	unsigned long n;
	char ma[] = "0123456789abcdef";
	void *add = va_arg(t, void *);

	unused(w);
	unused(s);

	if (add == NULL)
		return (write(1, "(nill)", 5));
	b[buff - 1] = '\0';
	unused(p);
	n = (unsigned long)add;
	while (n > 0)
	{
		b[d--] = ma[n % 16];
		n /= 16;
		l++;
	}
	if ((f & fzero) && !(f & fminus))
		pa = '0';
	if (f & fplus)
		ec = '+', l++;
	else if (f & fspace)
		ec = ' ', l++;
	d++;
	/*return (write(1, &b[a], buff - a - 1));*/
	return (write_pointer(b, d, l, w, f, pa, ec, ps));
}
/**
 * _nonprint - prints ascii codes of non print chars
 * @t: list of arguments
 * @s: size
 * @w: width
 * @b: buffer array
 * @p: precision
 * @f: flags
 * Return: number of chars printed
 */
int _nonprint(va_list t, char b[], int f, int s, int p, int w)
{
	int a = 0;
	int os = 0;
	char *st = va_arg(t, char *);

	unused(f);
	unused(w);
	unused(p);
	unused(s);

	if (st == NULL)
		return (write(1, "(null)", 6));
	while (st[a] != '\0')
	{
		if (_printable(st[a]))
			b[a + os] = st[a];
		else
			os += _hexacode(st[a], b, a + os);
		a++;
	}
	b[a + os] = '\0';
	return (write(1, b, i + os));
}
/**
 * _reverse - print reverse string
 * @t: list of arguments
 * @s: size
 * @b: buffer array
 * @w: width
 * @p: precision
 * @f: flags
 * Return: number of chars printed
 */
int _reverse(va_list t, char b[], int s, int p, int w, int f)
{
	char *st;
	int a, c = 0;

	unused(b);
	unused(f);
	unused(w);
	unused(s);

	st = va_arg(t, char *);

	if (st == NULL)
	{
		unused(p);

		st = ")NULL(";
	}
	for (a = 0; st[a]; a++)
		;
	for (a = a - 1; a >= 0; a--)
	{
		char x;

		x = st[a];
		write(1, &x, 1);
		c++;
	}
	return (c);
}
/**
 * _rot - print a string in rot13
 * @t: list of arguments
 * @s: size
 * @w: width
 * @f: flags
 * @p: precision
 * @b: buffer array
 * Return: numbers of chars printed
 */
int _rot(va_list t, char b[], int f, int w, int s, int p)
{
	char *st;
	char z;
	unsigned int a, k;
	int c = 0;
	char on[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQWSRTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	st = va_arg(t, char *);
	unused(b);
	unused(f);
	unused(w);
	unused(p);
	unused(s);

	if (st == NULL)
		st = "(AHYY)";
	for (a = 0; st[a]; a++)
	{
		for (k = 0; on[k]; k++)
		{
			if (on[k] == st[a])
			{
				z = out[k];
				write(1, &x, 1);
				c++;
				break;
			}
		}
		if (!on[k])
		{
			z = st[a];
			write(1, &x, 1);
			c++;
		}
	}
	return (c);
}

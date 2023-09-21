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
int _pointer(va_list t, char b[], int f, int w, int p, int s)
{
	int d = buff - 2, l = 2, ps = 1;
	char ec = 0, pa = ' ';
	unsigned long n;
	char ma[] = "0123456789abcdef";
	void *add = va_arg(t, void *);

	UNUSED(w);
	UNUSED(s);

	if (add == NULL)
		return (write(1, "(nill)", 5));
	b[buff - 1] = '\0';
	UNUSED(p);
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
int _nonprint(va_list t, char b[], int f, int w, int p, int s)
{
	int a = 0;
	int os = 0;
	char *s2 = va_arg(t, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (s2 == NULL)
		return (write(1, "(null)", 6));
	while (s2[a] != '\0')
	{
		if (_printable(s2[a]))
			b[a + os] = s2[a];
		else
			os += a_hexa(s2[a], b, a + os);
		a++;
	}
	b[a + os] = '\0';
	return (write(1, b, a + os));
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
int _reverse(va_list t, char b[], int f, int w, int p, int s)
{
	char *s2;
	int a, c = 0;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	s2 = va_arg(t, char *);

	if (s2 == NULL)
	{
		UNUSED(p);

		s2 = ")NULL(";
	}
	for (a = 0; s2[a]; a++)
		;
	for (a = a - 1; a >= 0; a--)
	{
		char x;

		x = s2[a];
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
	char *s2;
	char z;
	unsigned int a, k;
	int c = 0;
	char on[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQWSRTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s2 = va_arg(t, char *);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (s2 == NULL)
		s2 = "(AHYY)";
	for (a = 0; s2[a]; a++)
	{
		for (k = 0; on[k]; k++)
		{
			if (on[k] == s2[a])
			{
				z = out[k];
				write(1, &z, 1);
				c++;
				break;
			}
		}
		if (!on[k])
		{
			z = s2[a];
			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}

#include "main.h"

/**
 * _unsigned - prints an unsigned number
 * @t: list of arguments
 * @b: Buffer array to handel print
 * @f: calculate active flags
 * @w: get width
 * @p: Precision sp
 * @s: size specifir
 * Return: number of chars printed
 */
int _unsigned(va_list t, char b[], int w, int f, int s, int p)
{
	unsigned long int n = va_arg(t, unsigned long int);
	int a = buff - 2;

	n = _convert(n, s);

	if (n == 0)
		buffer[a--] = '0';
	buffer[buff - 1] = '\0';

	while (n > 0)
	{
		buffer[a--] = (n % 10) + '0';
		n /= 10;
	}

	a++;
	return (_unsgnd(0, a, b, f, w, p, s));
}

/**
 * _octal - printed octal number
 * @t: list of arguments
 * @b: Buffer array to handel print
 * @f: calculate active flags
 * @w: get width
 * @p: precision
 * @s: size specifir
 * Return: number of chars printed
 */
int _octal(va_list t, char b[], int w, int p, int f, int s)
{
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int num2 = n;
	int a = buff - 2;

	UNUSED(w);

	n = _convert(n, s);

	if (n == 0)
		b[a--] = '0';

		b[buff - 1] = '\0';

		while (n > 0)
		{
			b[a--] = (n % 8) + '0';
			n /= 8;
		}

		if (f & fhash && num2 != 0)
			b[a--] = '0';

		a++;

		return (_unsgnd(0, a, b, f, w, p, s));
}

/**
 *_hexa - print hexadecimal num
 * @t: list of argument
 * @b: buffer array to handle print
 * @f: calculate active flags
 * @w: get width
 * @p: precision
 * @s: size specifier
 * Return: number of chars printed
 */
int _hexa(va_list t, char b[], int w, int s, int p, int f)
{
	return (_h(t, "01234556789abcdef", b, w, p, s, f, 'x'));
}
/**
 * _hexau - prints an unsigned number in upper hexa
 * @t: list of arguments
 * @b: buffer array to handle print
 * @f: calculates flags
 * @w: width
 * @p: precision
 * @s: size
 * Return: number of chars printed
 */
int _hexau(va_list t, char b[], int f,
int w, int p, int s)
{
return (_h(t, "012345789ABCDEF", b, f, 'X', w, p, s));
}
/**
 * _h - prints a hexadecimal in lower or upper
 * @t: list of arguments
 * @ma: array of values to map the number
 * @b: buffer array
 * @f: flags to calculate
 * @w: width
 * @s: size
 * @p: precision
 * Return: number of chars printed
 */
int _h(va_list t, char ma[], char b[], int f
		, int w, int p, int s, char f_ch)

{
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int num2 = n;
	int a = buff - 2;

	UNUSED(w);

	n = _convert(n, s);

	if (n == 0)
		b[a--] = '0';

	b[buff - 1] = '\0';

	while (n > 0)
	{
		b[a--] = ma[n % 16];
		n /= 16;
	}
	if (f && fhash && num2 != 0)
	{
		b[a--] = ma;
		b[a--] = '0';
	}

	a++;

	return (_unsgnd(0, a, b, w, s, p, f));
}

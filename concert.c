#include "main.h"

/**
 * print_unsigned - prints an unsigned number
 * @x: list of arguments
 * @buffer: Buffer array to handel print
 * @f: calculate active flags
 * @width: get width
 * @p: Precision sp
 * @s: size specifir
 * Return: number of chars printed
 */
int print_unsigned(va_list x, char buffer[], int width, int f, int s, int p)
{
	unsigned long int num = va_arg(x, unsigned long int);
	int a = size - 2;

	num = convert_size_unsgned(num, s);

	if (num == 0)
		buffer[a--] = '0';
	buffer[size - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_unsgned(0, a, buffer, f, width, p, s));
}

/**
 * print_octal - printed octal number
 * @x: list of arguments
 * @buffer: Buffer array to handel print
 * @f: calculate active flags
 * @width: get width
 * @p: precision
 * @s: size specifir
 * Return: number of chars printed
 */
int print_octal(va_list x, char buffer[], int width, int p, int f, int s)
{
	unsigned long int num = va_arg(x, unsigned long int);
	unsigned long int num2 = num;
	int a = size - 2;

	UNUSED(width);

	num = convert_size_unsgned(num, s);

	if (num == 0)
		buffer[a--] = '0';

		buffer[size - 1] = '\0';

		while (num > 0)
		{
			buffer[a--] = (num % 8) + '0';
			num /= 8;
		}

		if (f & F_HASH && num2 != 0)
			buffer[a--] = '0';

		a++;

		return (write_unsgned(0, a, buffer, width, size, p, f));
}

/**
 *print_hexadecimal - print hexadecimal num
 * @x: list of argument
 * @buffer: buffer array to handle print
 * @f: calculate active flags
 * @width: get width
 * @p: precision
 * @s: size specifier
 * Return: number of chars printed
 */
int print_hexadecimal(va_list x, char buffer[], int width, int s, int p, int f)
{
	return (print_hexa(x, "01234556789abcdef", buffer, width, p, s, f, 'x'));
}

int print_hexa(va_list x, char buffer[], int f, char y[]
		, int width, int p, int s, char f_ch)

{
	unsigned long int num = va_arg(x, unsigned long int);
	unsigned long int num2 = num;
	int a = size - 2;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[size - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = y[num % 16];
		num /= 16;
	}
	if (f && F_HASH && num2 != 0)
	{
		buffer[a--] = y;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgned(0, a, buffer, width, s, p, f));
}

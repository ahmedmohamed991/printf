#include"main.h"
void print_buffer(char buffer[], int *x);


/**
 * _printf - printed function
 * @format: format.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{

	va_list l;

	va_start(l, format)
	if (format == NULL)
		return (-1);
	char buffer[buff];
	int a = 0, i;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[a++] = format[i];
			if (a == buff)
				print_buffer(buffer, &a);
			int _char++;
		}
		else
		{
			print_buffer(buffer, &a);
			int f = _flags(format, &a);
			int w = _width(format, &a, l);
			int p = _precision(format, &i, l);
			int s = _size(format, &i);
i++;
int pri = _handlep(format, &i, num, buffer, flags, width, precision, size);

			if (pri == -1)
				return (-1);
			print_char += pri;
		}
	}
	print_buffer(buffer, &x);

	va_end(l);

	return (_char);
}


/**
 * print_buffer - prints the contentes of the buffer if it exist
 * @buffer: array of chars
 * @x: index at which to add next char
 */
void print_buffer(char buffer[], int x)
{
	if (*x > 0)
		write(1, &buffer[0], *x);

	*x = 0;
}

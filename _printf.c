#include "main.h"
void print_buffer(char b[], int *bd);
/**
 * _printf - printf function
 * @format: format
 *Return: printed char
 */
int _printf(const char *format, ...)
{
	int a, pr = 0, _char = 0;
	int f, w, p, s, d, bd = 0;
	va_list l;
	char b[buff];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			b[bd++] = format[a];
			if (bd == buff)
				print_buffer(b, &bd);
			/* write(1, &format[a], 1); */
			_char++;
		}
		else
		{
			print_buffer(b, &bd);
			d = _flags(format, &a);
			w = _width(format, &a, l);
			p = _precision(format, &a, l);
			s = _getsize(format, &a);
			++a;
			pr = _handlep(format, &a, l, b, f, w, p, s);
			if (pr == -1)
				return (-1);
			_char += pr;
		}
	}
	print_buffer(b, &bd);

	va_end(l);
	return (_char);
}
/**
 * print_buffer - prints the contents of the buffer if it exist
 * @b: array of chars
 * @bd: index at which to add next char
 */
void print_buffer(char b[], int *bd)
{
	if (*bd > 0)
		write(1, &b[0], *bd);
	*bd = 0;
}



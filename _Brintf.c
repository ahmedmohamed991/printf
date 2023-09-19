#include "main.h"
void print_buffer(char b[], int *bd);
/**
 * _printf - printf function
 * @format: format
 *Return: printed char
 */
int _printf(const char *format, ...)
{
	int i, pr = 0, _char = 0;
	int f, w, p, s, bd = 0;
	va_list l;
	char b[buff];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			b[bd++] = format[i];
			if (bd == buff)
				print_buffer(b, &bd);
			/* write(1, &format[i], 1); */
			_char++;
		}
		else
		{
			print_buffer(b, &bd);
			d = _flags(format, &i);
			w = _width(format, &i, l);
			p = _precision(format, &i, l);
			s = _size(format, &i);
			++i;
			pr = _handlep(format, &i, l, b, f, w, p, s);
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



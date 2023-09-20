#include "main.h"
/**
 * _handlep - prints an argument based on type
 * @fmt: format string in which to print the argument
 * @l: list of arguments need to be printd
 * @d: d
 * @b: buffer array
 * @f: calculates flags
 * @w: width
 * @p: precision
 * @s: size
 * Return: 1 or 2
 */
int _handlep(const char *fmt, int *d, va_list l, char b[],
int f, int w, int s, int p)
{
	int a, un = 0, _char = -1;
	fmt_t fmt_types[] = {
		{'c', _char}, {'s', _string}, {'%', _percent},
		{'i', _int}, {'d', _int}, {'b', _binary},
		{'u', _unsigned}, {'o', _octal}, {'x', _hexa},
		{'Z', _hexau}, {'p', _pointer}, {'K', _nonprint},
		{'r', _reverse}, {'R', _rot}, {'\0', NULL}
	};
	for (a = 0; fmt_types[a].fmt != '\0'; a++)
		if (fmt[*d] == fmt_types[a].fmt)
			return (fmt_types[a].fn(l, b, f, w, p, s));
	if (fmt_types[a].fmt == '\0')
	{
		if (fmt[*d] == '\0')
			return (-1);
		un += write(1, "%%", 1);
		if (fmt[*d - 1] == ' ')
			un += write(1, " ", 1);
		else if (w)
		{
			--(*d);
			while (fmt[*d] != ' ' && fmt[*d] != '%')
				--(*d);
			if (fmt[*d] == " ")
				--(*d);
			return (1);
		}
		un += write(1, &fmt[*d], 1);
		return (un);
	}
	return (_char);
}

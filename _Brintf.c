#include"main.h"
void print_buffer(char buffer[], int *x);


/**
 * _printf - printed function
 * @format: format.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{

	va_list num;

	va_start(num, format);
	if (format == NULL)
		return (-1);
	char buffer[size];
	int x = 0, i;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[x++] = format[i];
			if (x == size)
				print_buffer(buffer, &x);
			int print_char++;
		}
		else
		{
			print_buffer(buffer, &x);
			int f = get_flags(format, &i);
			int width = get_width(format, &i, num);
			int pr = get_precision(format, &i, num);
			int size = get_size(format, &i);
i++;
int pri = handle_print(format, &i, num, buffer, flags, width, precision, size);

			if (pri == -1)
				return (-1);
			print_char += pri;
		}
	}
	print_buffer(buffer, &x);

	va_end(num);

	return (print_char);
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

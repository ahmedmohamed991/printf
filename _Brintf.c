#include"main.h"
/**
 * _printf - implementation of printf that hadels the 'c' , 's' ,and '%'
 *
 * @format: format string containing zero or more
 * Return: the number of characters printed
 * ( excluding the null byte used to end output to strings).
 *
 */
int _printf(const char *format, ...);
va_list numarg;
va_start(numarg, format);


int a = 0;
int x;

for (x = 0; format[x]; x++)
{
	if (format[x] == '%')
	{
		x++;
		if (format[x] == 'c')
		{
			char b = va_arg(numarg, int);

			putchar(c);
			a++;
		}
		else if (format[x] == 's')
		{
			char *s = va_arg(numarg, char*);

			for (; *s; s++, a++)
			{
				putchar(*s);
			}
		}
		else if (format[x] == '%')
		{
			putchar('%');
			a++;
		}
		else
		{
			putchar('%');
			putchar(format[x]);
			a += 2;
		}
	}
	else
	{
		putchar(format[x]);
		a++;
	}
}
va_end(numarg);
return (a);
}
/**
 * main - Entry point of the program.
 *
 * this function demonstrates the usage of the _printf function
 *
 * Return: Always return 0 to indicate successful execution.
 */

int main(void)
{
	char b = 'a';
		char *s = "hello";
	int a = _printf("Character: %c\nString: %s\npercent: %%\n", b, s);

	printf("Number of characters printed: %d\n", a);
	return (o);
}

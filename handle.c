#include "main.h"
/**
 * _handle - calculates current flags
 * @format: format string in which to print arguments
 * @a: take a parameter
 * Return: flags
 */
int _handle(const char *format, int *a)
{
	int b, c;
	int f = 0;
	const char F[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {f_minus, f_plus, s_zero, f_hash, f_space, 0};

	for (c = *a + 1; format[c] != '\0'; c++)
	{
		b = 0;
		while (F[b] != '\0')
		{
			if (format[c] == F[b])
			{
				f |= FLAG_ARR[b];
				break;
			}
			b++;
		}

		if (F[b] == 0)
			break;
	}
	*a = c - 1;

	return (f);
}

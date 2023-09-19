#include "main.h"

/**
 * get_flags - calculates flags
 * @format: formatted string in which to print the arg
 * @x: take a parameter
 * Return: flags
 */

int get_flags(const char *format, int *x)
{
	const char flag1[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_array[] = {f_minus, f_plus, f_zero, f_hash, f_space, 0};
	int a, y, flags = 0;

	for (y = *x + 1; format[y] != '\0'; y++)
	{
		for (a = 0; flag1[a] != '\0'; a++)
			if (format[y] == flag1[a])
				flags |= flags_array[a];
		break;
	}
	if (flag1[a] == 0)
		break;
}
*x = y - 1;

return (flags);
}

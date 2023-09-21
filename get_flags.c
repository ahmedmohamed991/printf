#include "main.h"

/**
 * _flags - calculates flags
 * @format: formatted string in which to print the arg
 * @a: take a parameter
 * Return: flags
 */

int _flags(const char *format, int *a)
{
	const char flag1[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_array[] = {fminus, fplus, fzero, fhash, fspace, 0};
	int j, y, f = 0;

	for (y = *a + 1; format[y] != '\0'; y++)
	{
		int found_flag = 0;

		for (j = 0; flag1[j] != '\0'; j++)
			if (format[y] == flag1[j])
			{
				f |= flags_array[j];
				found_flag = 1;
				break;
				}
	if (!found_flag)
		break;
	}
*a = y - 1;

return (f);
}

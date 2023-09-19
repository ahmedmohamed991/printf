#include "main.h"
/**
 * _printable - check if a char is printable
 * @c: char to check
 * Return: 1 if c is printed, 0 otherwise
 */
int _printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * a_hexa - append ascii in hexa code to buffer
 * @b: array of buffer
 * @a: index
 * @ascii: ASSCI CODE
 * Return: Always 3
 */
int a_hexa(char ascii, char b[], int a)
{
	char _ma[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;
	b[a++] = '\\';
	b[a++] = 'x';
	b[a++] = _ma[ascii / 16];
	b[a] = _ma[ascii % 16];

	return (3);
}
/**
 * _digit - check if a char is digit
 * @c: char to be checked
 * Return: 1 if c ia a digit, 0 otherwise
 */
int _digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * _size - specify size
 * @s: number indicating the type to be cast
 * @n: number to cast
 * Return: casted value
 */
long int _size(long int n, int s)
{
	if (s == _long)
		return (n);
	else if (size == _short)
		return ((short)n);
	return ((int)n);
}
/**
 * _convert - casts a number to the specified size
 * @s: number indicate the type to be cast
 * @n: number to be casted
 * Return: casted value
 */
long int _convert(unsigned long int n, int s)
{
	if (s == _long)
		return (n);
	else if (s == _short)
		return ((unsigned short)n);
	return ((unsigned int)n);
}

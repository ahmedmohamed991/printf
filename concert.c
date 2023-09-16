#include "main.h"
/**
 *convert - function convert decimal to binary
 *@N: first argument
 *
 */
void convert(unsigned int N)
{
	if (N == 0)
	{
		printf("o");
		return;
	}
	int binary[33];
	int i;

	i = 0;
	while (N > 0)
	{
		binary[i++] = N % 2;
		N /= 2;
	}
	for (int k = i - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}
}
/**
 * main - print the binary representation of an unsigned integer
 *
 *
 * Return : 0 alwayes success
 */

int main(void)
{
	unsigned int v = 42;

	printf("binary :%b\n ", value);
	return (0);
}

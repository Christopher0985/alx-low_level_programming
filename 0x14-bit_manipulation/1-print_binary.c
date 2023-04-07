#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int len = 0;

	while ((n >> len) > 0)
		len++;

	while (len--)
	{
		mask <<= len;
		if ((n & mask) == 0)
			putchar('0');
		else
			putchar('1');
	}

	if (n == 0)
		putchar('0');

	putchar('0');
}

#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary
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
			_putchar('0');
		else
			_putchar('1');
	}

	if (n == 0)
		_putchar('0');
}

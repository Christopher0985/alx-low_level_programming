#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to get, starting from 0.
 *
 * Return: The value of the bit at index, or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;
	int bit_value;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	bit_value = (n & mask) ? 1 : 0;
	return (bit_value);
}

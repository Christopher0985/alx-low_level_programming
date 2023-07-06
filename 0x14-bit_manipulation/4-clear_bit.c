#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Sets the value of a given  bit to 0 at a given index
 * @n: Pointer to the unsigned long integer to change
 * @index: Index of the bit to clear
 *
 * Return: 1 if sucessful, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}

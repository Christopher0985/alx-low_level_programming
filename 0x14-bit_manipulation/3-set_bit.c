#include <stdio.h>
#include "main.h"

/**
 * set_bit - Sets a bit to 1 at a given index.
 * @n: Pointer to the unsigned long int to change.
 * @index: Index of the bit to set to 1.
 *
 * Return: 1 if successful, -1 if failure occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n |= (1UL << index);

	return (1);
}

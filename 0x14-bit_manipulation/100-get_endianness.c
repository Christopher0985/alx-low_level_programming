#include "main.h"
#include <stdio.h>

/**
 * get_endianness - Checks whether a machine is little or big endian.
 *
 * Return: 0 for big endian, 1 for little one.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *ptr = (unsigned char *)&num;

	return ((int)(*ptr));
}

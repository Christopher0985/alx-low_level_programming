#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary num to an unsigned int.
 * @b: Pointer to a string of binary num.
 *
 * Return: The converted num, or 0 if there is an invalid char or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = (result << 1) + (*b - '0');
		b++;
	}

	return (result);
}

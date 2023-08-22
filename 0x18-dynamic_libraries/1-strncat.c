#include "main.h"

/**
 * _strncat - Concatenates two strings up to a specified length.
 * @dest: The destination string.
 * @src: The source string to be added.
 * @n: The maximum number of characters to be concatenated.
 *
 * Return: Pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_length = 0;

	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	for (int i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + n] = '\0';

	return (dest);
}

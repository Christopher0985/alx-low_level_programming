#include "main.h"

/**
 * _memcpy - Copies data from source to destination.
 * @dest: Pointer to the destination memory.
 * @src: Pointer to the source memory.
 * @n: Number of bytes to be copied.
 * 
 * Return: Pointer to the altered destination memory.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *destination = dest;

	while (n--)
	{
		*destination = *src;
		destination++;
		src++;
	}
	return (dest);
}

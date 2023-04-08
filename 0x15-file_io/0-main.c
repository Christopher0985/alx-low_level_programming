# include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @av: An array of strings containing the command-line arguments
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int ac, char **av)
{
	ssize_t n;

	if (ac != 2)
	{
		printf("Usage: %s filename\n", av[0]);
		exit(1);
	}
	n = read_textfile(av[1], 114);
	printf("\n(printed chars: %li)\n", n);
	n = read_textfile(av[1], 1024);
	printf("\n(printed chars: %li)\n", n);
	return (0);
}

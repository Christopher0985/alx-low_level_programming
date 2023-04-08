#include "main.h"
#include <stdlib.h>

#define BUFSIZE 1024

/**
 * main - copies the content of a file to another file
 *
 * @ac: the number of arguments passed
 * @av: the arguments passed
 *
 * Return: On success: 0, On error: Exit status
 */
int main(int ac, char **av)
{
	int fd1, fd2, r, w;
	char buf[BUFSIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	fd2 = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd2 < 0)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);

	while ((r = read(fd1, buf, BUFSIZE)) > 0)
	{
		w = write(fd2, buf, r);
		if (w < 0)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	}

	if (r < 0)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	if (close(fd1) < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1), exit(100);

	if (close(fd2) < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2), exit(100);

	return (0);
}

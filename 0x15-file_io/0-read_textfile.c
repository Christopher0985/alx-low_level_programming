#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a text file and print its content to the POSIX STDOUT.
 * @filename: The name of the text file being read.
 * @letters: The num of letters to be read and printed.
 *
 * Return: The actual num of bytes read and printed on success,
 *         or 0 when the function fails or the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t num_bytes_read;
	ssize_t num_bytes_written;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	num_bytes_read = read(fd, buffer, letters);
	if (num_bytes_read <= 0)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	num_bytes_written = write(STDOUT_FILENO, buffer, num_bytes_read);

	free(buffer);
	close(fd);

	if (num_bytes_written != num_bytes_read)
		return (0);

	return (num_bytes_written);
}

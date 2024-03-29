#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append to
 * the file (a NULL-terminated string).
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	int size = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[size])
			size++;

		bytes_written = write(fd, text_content, size);

		if (bytes_written == -1 || bytes_written != (ssize_t)size)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

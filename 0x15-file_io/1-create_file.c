#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file and writes the given text content to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write
 * to the file (a NULL-terminated string).
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	int size = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
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

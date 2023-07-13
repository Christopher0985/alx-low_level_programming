#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

/**
 * create_file - Creates a file with the given filename.
 * @filename: The name of the file to be created.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: 1 if successful, otherwise -1.
 *         If filename is NULL, returns -1.
 *         If text content is NULL, creates an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len;
	int write_len;

	if (filename == NULL)
	return (-1);

	len = 0;

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		write_len = write(fd, text_content, len);
		if (write_len != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

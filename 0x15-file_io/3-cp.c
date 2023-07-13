#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * copy_file_from - Copies  contents of the source file to a buffer.
 *
 * @file_from: The source file to copy from.
 * @buffer: The buffer to store the copied content.
 *
 * Return: The num of bytes read on success, otherwise -1
 */
ssize_t copy_file_from(const char *file_from, char *buffer)
{
	int fd_from = open(file_from, O_RDONLY);
	ssize_t read_len;

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from);
		return (-1);
	}

	read_len = read(fd_from, buffer, BUFFER_SIZE);
	close(fd_from);

	if (read_len == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from);

	return (read_len);
}

/**
 * copy_file_to - Copies the content from the buffer to the other file.
 *
 * @file_to: The  file to copy to.
 * @buffer: The buffer containing the content to copy.
 * @buffer_len: The length of the content in the buffer.
 *
 * Return: 0 on success, or -1 on failure.
 */
int copy_file_to(const char *file_to, char *buffer, ssize_t buffer_len)
{
	int fd_to = open(file_to, O_WRONLY | O_TRUNC | O_CREAT,
			 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	ssize_t write_len;

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		return (-1);
	}

	write_len = write(fd_to, buffer, buffer_len);
	close(fd_to);

	if (write_len != buffer_len)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		return (-1);
	}

	return (0);
}

/**
 * main - Entry point of the program.
 *
 * @argc: The num of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or exit with the suitable error code.
 */
int main(int argc, char *argv[])
{
	char *buffer;
	ssize_t read_len;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(100);
	}

	read_len = copy_file_from(argv[1], buffer);
	if (read_len == -1)
	{
		free(buffer);
		exit(98);
	}

	if (copy_file_to(argv[2], buffer, read_len) == -1)
	{
		free(buffer);
		exit(99);
	}

	free(buffer);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
* print_error - Prints the error message to standard error and terminates
* the program with exit status 98.
* @msg: The error message to be displayed.
*/
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
* print_elf_header - Displays the contents of the ELF header.
* @header: Pointer to the ELF header structure.
*/
void print_elf_header(const Elf64_Ehdr *header)
{
	printf("Magic:   %02x %02x %02x %02x\n",
		header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
		header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);

	printf("Class:   %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ?
			"ELF32" : "ELF64");

	printf("Data:    %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" :
			"2's complement, big endian");

	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	printf("OS/ABI:  %s\n", (header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ?
			"UNIX System V ABI" : "Others");

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type:    0x%04x\n", header->e_type);

	printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

/**
* main - Entry point of the program.
* @argc: The number of command-line arguments.
* @argv: An array of strings containing the command-line arguments.
* Return: 0 if the program executes successfully, 98 in case of an error.
*/
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Failed to open file");

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1)
		print_error("Failed to read file");

	if (bytes_read != sizeof(header))
		print_error("Invalid file format");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	print_elf_header(&header);

	close(fd);
	return (0);
}

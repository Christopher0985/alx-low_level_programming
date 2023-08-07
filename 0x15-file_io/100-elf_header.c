#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error_exit - Display an error message to stderr and exit with the given code
 * @code: The exit code.
 * @message: The error message to display.
 */
void error_exit(int code, const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(code);
}

/**
 * print_elf_info - Print ELF header information.
 * @header: Pointer to the ELF header.
 */
void print_elf_info(Elf64_Ehdr *header)
{
	int i;
	const char *class_str;
	const char *data_str;
	const char *version_str;
	const char *osabi_str;
	const char *type_str;

	class_str = (header->e_ident[EI_CLASS] == ELFCLASS64) ?
		"ELF64" : "ELF32";
	data_str = (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" : "2's complement, big endian";
	version_str = (header->e_ident[EI_VERSION] == EV_CURRENT) ?
		"1 (current)" : "UNKNOWN";
	osabi_str = (header->e_ident[EI_OSABI] == ELFOSABI_NONE) ?
		"UNIX - System V" : "UNKNOWN";
	type_str = (header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
		(header->e_type == ET_DYN) ? "DYN (Shared object file)" :
		(header->e_type == ET_REL) ? "REL (Relocatable file)" :
		"UNKNOWN";

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n", class_str);
	printf("  Data:                              %s\n", data_str);
	printf("  Version:                           %s\n", version_str);
	printf("  OS/ABI:                            %s\n", osabi_str);
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", type_str);
	printf("  Entry point address:               0x%lx\n",
			(unsigned long)header->e_entry);
}

/**
 * main - Display the information contained in the ELF header of an ELF file.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit(98, "Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit(98, "Error: Cannot read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1]
			!= ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
		error_exit(98, "Error: Not an ELF file");

	print_elf_info(&header);

	if (close(fd) == -1)
		error_exit(98, "Error: Cannot close file");

	return (0);
}

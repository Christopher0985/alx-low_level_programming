#include <stdio.h>
#include <elf.h>

/**
 * print_elf_header_info - Prints information about an ELF header
 * @header: Pointer to the ELF header to print
 *
 * This function prints information about the specified ELF header, including
 * the magic number, file class, data encoding, entry point address, program
 * header table offset, section header table offset, and other fields.
 */
void print_elf_header_info(void *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (int i = 0; i < EI_NIDENT; i++)

	{
		printf("%02x ", header->e_ident[i]);
	}

	printf("\n");
	printf("  Class:                             %s\n",
		(header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		(header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement,
			little endian" : "2's complement, big endian");
	printf("  Version:                           %d\n",
		header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n",
		header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
		header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n",
		header->e_type);
	printf("  Entry point address:               %lx\n",
		header->e_entry);
	printf("  Start of program headers:          %ld (bytes into file)\n",
		header->e_phoff);
	printf("  Start of section headers:          %ld (bytes into file)\n",
		header->e_shoff);
	printf("  Flags:                             %d\n", header->e_flags);
	printf("  Size of this header:               %d (bytes)\n",
		header->e_ehsize);
	printf("  Size of program headers:            %d (bytes)\n",
		header->e_phentsize);
	printf("  Number of program headers:          %d\n", header->e_phnum);
	printf("  Size of section headers:            %d (bytes)\n",
		header->e_shentsize);
	printf("  Number of section headers:          %d\n", header->e_shnum);
	printf("  Section header string table index: %d\n",
		header->e_shstrndx);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *destination_file);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocate a 1024-byte buffer for file operations.
 * @destination_file: The name of the file to store data in.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *destination_file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", destination_file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Close a file descriptor and handle errors.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int close_status;

	close_status = close(fd);

	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the contents of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit codes:
 *   97 - Incorrect argument count.
 *   98 - Unable to read from file_from.
 *   99 - Unable to create or write to file_to.
 *   100 - Unable to close file descriptors.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_bytes = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(destination_fd, buffer, read_bytes);
		if (destination_fd == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(source_fd, buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_file_descriptor(source_fd);
	close_file_descriptor(destination_fd);

	return (0);
}

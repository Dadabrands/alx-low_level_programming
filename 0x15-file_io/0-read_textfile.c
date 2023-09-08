#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a text file and print its contents to STDOUT.
 * @filename: The name of the text file to read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer; /* To store the content read from the file */
	ssize_t file_descriptor; /* File descriptor for the opened file */
	ssize_t bytes_read; /* Number of bytes read from the file */
	ssize_t bytes_written; /* Number of bytes written to STDOUT */

	/* Open the file in read-only mode */
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	/* Allocate memory for the buffer to store the file content */
	buffer = malloc(sizeof(char) * letters);

	/* Read the content of the file into the buffer */
	bytes_read = read(file_descriptor, buffer, letters);

	/* Write the content from the buffer to STDOUT */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	/* Clean up allocated memory and close the file */
	free(buffer);
	close(file_descriptor);

	/* Return the number of bytes successfully written to STDOUT */
	return (bytes_written);
}

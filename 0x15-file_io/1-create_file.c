#include "main.h"

/**
 * create_file - Create a file with specified content.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to the string content to write to the file.
 *
 * Return: On success, return 1. On failure, return -1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	/* Calculate the length of the text content if provided */
	if (text_content != NULL)
	{
		for (content_length = 0; text_content[content_length];)
			content_length++;
	}

	/* Create the file with read and write permissions (rw-------) */
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	/* Check for errors during file creation */
	if (file_descriptor == -1)
		return (-1);

	/* Write the text content to the file */
	bytes_written = write(file_descriptor, text_content, content_length);

	/* Check for errors during write operation */
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	/* Close the file and return success status */
	close(file_descriptor);
	return (1);
}

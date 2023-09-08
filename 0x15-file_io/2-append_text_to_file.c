#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to the string to append to the file.
 *
 * Return: On success, return 1. On failure, return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
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

	/* Open the file in write-only mode, append if it exists */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	/* Check for errors during file open */
	if (file_descriptor == -1)
		return (-1);

	/* Write the text content to the end of the file */
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

#include "holberton.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: string to write to the file
 *
 * Return: 1 on Success or -1 on Failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int filed, w, i;

	for (i = 0 ; text_content[i] != '\0' ; i++)
		;

	filed = open(filename, O_WRONLY | O_APPEND);

	if (filed == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		text_content = "";
	}

	if (text_content)
	{
		w = write(filed, text_content, i);

		if (w == -1)
		{
			return (-1);
		}
	}

	if (text_content == NULL)
	{
		if (filename == NULL)
		{
			return (-1);
		}
		return (-1);
	}

	close(filed);
	return (1);
}

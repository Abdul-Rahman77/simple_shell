#include "shell.h"
/**
 * _getchar - reads a char from stdin
 * Return: the char read
 */

ssize_t _getchar(void)
{
	char c;

	ssize_t read_char = read(STDIN_FILENO, &c, sizeof(char));

	return ((read_char == 0) ? EOF : c);
}

/**
 * _getline - Reads a lineptr of input
 * @lineptr: a pointer to the char pointer storing an address
 * @n: a pointer holding the address of an int varaible
 * @stream: pointer to the stream
 * Return: the number of chars read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int character = 0;
	size_t position = 0;
	ssize_t counter = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 120;
		*lineptr = (char *)malloc(sizeof(char) * (*n));
		if (*lineptr == NULL)
			return (-1);
	}
	while ((character = _getchar()) != EOF)
	{
		if ((position + 1) >= *n)
		{
			size_t size = (*n * 2);
			char *line = realloc(*lineptr, size);

			if (line == NULL)
			{
				return (-1);
			}
			*lineptr = line;
			*n = size;
		}
		(*lineptr)[position] = (char)character;
		counter++;
		if (character == '\n')
		{
			(*lineptr)[position] = '\0';
			break;
		}
		position++;
	}
	return ((counter == 0) ? -1 : (counter - 1));
}

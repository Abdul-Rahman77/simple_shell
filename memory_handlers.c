#include "shell.h"

/**
 * free_args - frees a pointer to character pointer [an array of char pointers]
 * @args: the array to be freed;
 */

void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}

	free(args);
}

/**
 * _malloc - allocates memory
 * @size: the size to be used in allocation
 * Return: the allocated memory
 */

char *_malloc(size_t size)
{
	char *str = (char *)malloc(sizeof(char) * size);

	if (str == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	return (str);
}

/**
 * _realloc - reallocates memory for an existing malloc string
 * @str: the char pointer to be reallocated memory for
 * Return: a pointer to the newly allocated memory
 */

char *_realloc(char *str, size_t size)
{
	str = realloc(str, size);

	if (str == NULL)
	{
		perror("Memory reallocation error");
		exit(EXIT_FAILURE);
	}

	return (str);
}

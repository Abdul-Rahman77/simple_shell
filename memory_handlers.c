#include "shell.h"

/**
 * free_args - frees a pointer to character pointer [an array of char pointers]
 * @args: the array to be free;
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
 * is_malloc - frees a memory allocated to str
 * @str: the string with memory allocation
 * Return: false if str is not NULL and true for the otherwise
 */

bool is_malloc(char *str)
{
	if (str == NULL)
	{
		perror("Memory allocation failed");
		return (true);
	}

	return (false);
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
 * @size: the size of the new new allocation
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

/**
 * realloc_args - reallocates memory for args
 * @args: the pointer to the allocated memory to be reallocated;
 * @size: the size of the new memory
 * Return: pointer to the newly allocated memory
 */

char **realloc_args(char **args, size_t size)
{
	args = (char **)realloc(args, size * sizeof(char));
	if (args == NULL)
	{
		perror("Memory reallocation failed");
		exit(EXIT_FAILURE);
	}

	return (args);
}

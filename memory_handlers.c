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
 * alloc_token - reallocates memory for an existing malloc string
 * @token: the char pointer to be reallocated memory for
 * Return: a pointer to the newly allocated memory
 */

char *alloc_token(const char *token)
{
	char *new_token = _strdup(token);

	if (!new_token)
	{
	perror("Memory allocation error");
	exit(EXIT_FAILURE);
	}
	return (new_token);
}

/**
 * realloc_args - reallocates memory for args
 * @args: the pointer to the allocated memory to be reallocated;
 * @size: the size of the new memory
 * Return: pointer to the newly allocated memory
 */

char **realloc_args(char **args, size_t size)
{
	char **tok = (char **)realloc(args, (size + 1) * sizeof(char *));

	if (!tok)
	{
		perror("Memory allocation error");
		free(args);
		exit(EXIT_FAILURE);
	}
	return (tok);
}

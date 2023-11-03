#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * @str: the string under study
 * Return: the total number of characters in the str
 */

size_t _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcpy - copies a string into another
 * @dest: the string to be copied into
 * @src: the source string
 * Return: the destination string
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (dest[i] != '\0' || src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to be duplicated
 * Return: a pointer to the new string
 */

char *_strdup(const char *str)
{
	int i, j;
	char *dest;

	if (str == NULL)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0';)
	{
		j++;
	}
	dest = malloc(sizeof(char) * j + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < j; i++)
	{
		dest[i] = str[i];
	}
	dest[j] = str[j];
	return (dest);
}

/**
 * tokenizer - generates token from the command entered
 * @command: the command to be parsed and tokenized
 * Return: the tokens generated
 */


char **tokenizer(char *command) {
	char *token, *command_copy;
	char *delim = " \t\n";
	char **tok = NULL;
	int i = 0;

	tok = (char **)calloc(1, sizeof(char *));
	if (tok == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	command_copy = _strdup(command);
	token = strtok(command_copy, delim);
	while (token != NULL)
	{
		tok = (char **)realloc(tok, (i + 2) * sizeof(char *));
		if (tok == NULL)
		{
		    perror("Memory allocation error");
		    free(command_copy);
		    exit(EXIT_FAILURE);
		}
		tok[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	tok = (char **)realloc(tok, (i + 1) * sizeof(char *));
	if (tok == NULL)
	{
		perror("Memory allocation error");
		free(command_copy);
		exit(EXIT_FAILURE);
	}

	tok[i] = NULL;
	free(command_copy);
	return tok;
}


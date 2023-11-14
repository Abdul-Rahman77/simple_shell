#include "shell.h"

/**
 * _strncat - concatenate two strings
 * using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncpy - copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}

/**
 * tokenizer - generates token from the command entered
 * @command: the command to be parsed and tokenized
 * Return: the tokens generated
 */

char **tokenizer(char *command)
{
	char *token, *command_copy, *delim = " \t\n";
	int i = 0;
	char **tok = (char **)malloc(sizeof(char *));

	if (!tok)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	command_copy = _strdup(command);
	if (!command_copy)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	while ((token = strtok(i == 0 ? command_copy : NULL, delim)))
	{
		tok = realloc_args(tok, i);
		tok[i] = alloc_token(token);
		i++;
	}
	tok = realloc_args(tok, i);
	tok[i] = NULL;

	free(command_copy);
	return (tok);
}


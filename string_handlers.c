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
	size_t i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
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
	size_t len;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str) + 1;

	duplicate = (char *)malloc(len);
	if (duplicate == NULL)
	{
		return (NULL);
	}

	_strcpy(duplicate, str);

	return (duplicate);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */

char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}


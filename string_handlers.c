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

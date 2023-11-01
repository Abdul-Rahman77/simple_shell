#include "shell.h"

/**
 * _putchar - prints a character to the stdout
 * @c: The character to be printed
 * Return: the write to the stdout
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}

/**
 * print - writes a series of characters to stdout
 * @str: the string to be printed
 */

void print(const char *str)
{
	size_t size = _strlen(str) * sizeof(char);

	write(STDOUT_FILENO, str, size);
}

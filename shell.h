#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* stdout_handlers.c */
int _putchar(char c);
void print(const char *str);

/* string_handlers */
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);

#endif

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* stdout_handlers.c */
int _putchar(char c);
void print(const char *str);
void prompt(void);
void signal_handler(int signal_int);

/* string_handlers */
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char **tokenizer(char *command);

/* stdin_handlers */
ssize_t _getchar(void);
ssize_t _getline(char **line, size_t *size, FILE *stream);

/* memory_handlers */
void free_args(char **args);
char *_malloc(size_t size);
char *_realloc(char *str, size_t size);

/* execution_handlers */
void execute_command(char **args);
bool is_found(char *executable);

/* path_handlers */
char *getpath(const char *filename, char *program_name);

#endif

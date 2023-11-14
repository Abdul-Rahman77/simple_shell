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
char *_strcat(char *dest, const char *src);
char **tokenizer(char *command);

/* string_handlers2 */
char **whiletok(char **tok, char *command_copy, char *delim);

/* stdin_handlers */
ssize_t _getchar(void);
ssize_t _getline(char **line, size_t *size, FILE *stream);

/* memory_handlers */
void free_args(char **args);
char *_malloc(size_t size);
char *alloc_token(const char *token);
bool is_malloc(char *str);
char **realloc_args(char **args, size_t size);

/* execution_handlers */
void execute_command(char **args);
bool is_found(char *executable);

/* path_handlers */
char *getpath(const char *filename, char *program_name);
char *get_full_path(const char *command, char *token);

/* command dispatching handlers */
typedef struct get_command
{
	char *command_name;
	void (*command_function)(char **args);
} get_command;

/* inbuilt handlers */
void (*is_command(char **args))(char **args);
void _exit_(char **args);

#endif

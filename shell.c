#include "shell.h"

/**
 * builtin - handles builtin commands
 * @args: The array of the tokenized commands
 * @command: the command;
 * @len: the number of chars read
 * @buffer_size: the size of the input to be read
 * Return: NULL if the command is not a builtin
 */

char **builtin(char **args, char *command, ssize_t len, size_t buffer_size)
{
	prompt();
	len = getline(&command, &buffer_size, stdin);
	if (len == -1)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	args = tokenizer(command);
	if (is_found(args[0]) == true)
	{
		execute_command(args);
		free_args(args);
		free(command);
		return (NULL);
	}
	free(command);
	return (args);
}

/**
 * execute - handles the else statement in main
 * @args: the tokenized array of command
 * @command: the command
 * @prog: the first argument of main
 */

void execute(char **args, char *command, char *prog)
{
	void (*built)(char **args);

	if (is_found(args[0]))
	{
		execute_command(args);
		free_args(args);
		free(command);
	}
	else if ((is_command(args)))
	{
		built = is_command(args);
		free(command);
		built(args);
	}
	else
	{
		perror(prog);
		free_args(args);
		free(command);
	}
}

/**
 * main - points of start of execution
 * @argc: the command line arguments count
 * @argv: the array of command line arguments
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	char *command, **args;
	size_t buffer_size = 128;
	ssize_t command_length = 0;

	signal(SIGINT, signal_handler);
	while (argc)
	{
		command = NULL;
		args = builtin(args, command, command_length, buffer_size);
		if (!args)
			continue;
		else
		{
			args[0] = getpath(args[0]);
			if (args[0] == NULL)
			{
				free(command);
				free_args(args);
				continue;
			}
			execute(args, command, argv[0]);
		}
	}
	return (0);
}

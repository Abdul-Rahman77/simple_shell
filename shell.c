#include "shell.h"

/**
 * builtin - handles builtin commands
 * @args: The array of the tokenized commands
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
	void (*built)(char **args);

	signal(SIGINT, signal_handler);
	while (argc && argv)
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
			if (is_found(args[0]))
			{
				execute_command(args);
				free_args(args);
				free(command);
			}
			else if ((built = is_command(args)))
			{
				free(command);
				built(args);
			}
			else
			{
				perror(argv[0]);
				free_args(args);
				free(command);
			}
		}
	}
	return (0);
}

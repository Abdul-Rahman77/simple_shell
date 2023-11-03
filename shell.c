#include "shell.h"

/**
 * main - points of start of execution
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	char *command, **args;
	size_t buffer_size = 128;
	ssize_t command_length;
	
	signal(SIGINT, signal_handler);
	while (argc)
	{
		command = NULL;
		prompt();
		command_length = _getline(&command, &buffer_size, stdin);
		if (command_length == -1)
		{
			_putchar('\n');
			free(command);
			exit(EXIT_SUCCESS);
		}
		args = tokenizer(command);
		if (is_found(args[0]) == true)
		{
			execute_command(args);
			free_args(args);
			free(command);
		}
		else
		{
			args[0] = getpath(args[0], argv[0]);
			if (args[0] == NULL)
			{
				free(command);
				free_args(args);
				continue;
			}
			execute_command(args);
			free_args(args);
			free(command);
		}
	}
	return (0);
}

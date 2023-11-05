#include "shell.h"

/**
 * main - points of start of execution
 * Return: 0 always
 */

int main(void)
{
	char *command, **args;
	size_t buffer_size = 128;
	ssize_t command_length;
	
	signal(SIGINT, signal_handler);
	while (true)
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
			args[0] = find_command_path(args[0]);
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

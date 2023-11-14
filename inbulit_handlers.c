#include "shell.h"

/**
 * is_command - checks if an entered command is an inbuilt command
 * @args: the array of commands to be checked
 * Return: NULL if commands mismatch and returns the command if match is found
 */

void (*is_command(char **args))(char **args)
{
	int i = 0, j;
	get_command command[] = {
		{"exit", _exit_},
		{NULL, NULL}
	};

	for (i = 0; command[i].command_name; i++)
	{
		j = 0;
		if (command[i].command_name[j] == args[0][j])
		{
			for (j = 0; args[0][j] != '\0'; j++)
			{
				if (command[i].command_name[j] != args[0][j])
					break;
			}
			if (args[0][j] == '\0')
			{
				return (command[i].command_function);
			}
		}
	}
	return (0);
}

/**
 * _exit - exits the simple shell program
 * @args: the tokenized command
 */

void _exit_(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		if (status < 0)
			status = 2;
		free_args(args);
		exit(status);
	}
	free_args(args);
	exit(EXIT_SUCCESS);
}

#include "shell.h"

/**
 * execute_command - creates a child process and executes a file.
 * @args: the pointer to the command to be executed
 * Return: args
 */

void execute_command(char **args)
{
	pid_t get_pid;
	int status;

	get_pid = fork();
	if (get_pid == -1)
	{
		free_args(args);
		perror("Child process creation failed!");
		exit(EXIT_FAILURE);
	}
	if (get_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			free_args(args);
			perror("Execution unsuccessful!");
			exit(EXIT_FAILURE);
		}
	}

	wait(&status);
}

/**
 * is_found - iterates through the path to find executable
 * @executable: the executable file
 * Return: true if found and false if the otherwise
 */

bool is_found(char *executable)
{
	return ((access(executable, F_OK) != -1) ? true : false);
}

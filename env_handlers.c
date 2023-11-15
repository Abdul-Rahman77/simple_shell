#include "shell.h"


/**
 * _getenv - gets the variable of the global variable
 * @env_name: env_name of the global variable
 * Return: str of variable
 */
char *_getenv(const char *env_name)
{
	int i, j;
	char *variable;

	if (!env_name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (env_name[j] == environ[i][j])
		{
			while (env_name[j])
			{
				if (env_name[j] != environ[i][j])
					break;

				j++;
			}
			if (env_name[j] == '\0')
			{
				variable = (environ[i] + j + 1);
				return (variable);
			}
		}
	}
	return (0);
}

/**
 * env - prints the current environment
 * @args: array of arguments
 */
void env(char **args __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		print(environ[i]);
		print("\n");
	}

}

/**
 * _setenv - sets an environment variable
 * @args: tokenized command
 */
void _setenv(char **args)
{
	int i, j, y;

	if (!args[1] || !args[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;

				j++;
			}
			if (args[1][j] == '\0')
			{
				y = 0;
				while (args[2][y])
				{
					environ[i][j + 1 + y] = args[2][y];
					y++;
				}
				environ[i][j + 1 + y] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concatenator(args[1], "=", args[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _unsetenv - unset environment variable
 * @args: the tokenized command
 */
void _unsetenv(char **args)
{
	int i, j;

	if (args == NULL)
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;

				j++;
			}
			if (args[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

/**
 * _exit_ - exits the shell with or without a return of status n
 * @args: array of words of the entered line
 */
void _exit_(char **args)
{
	int i, n;

	if (args[1])
	{
		n = _atoi(args[1]);
		if (n <= -1)
			n = 2;
		free_args(args);
		exit(n);
	}
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	exit(0);
}

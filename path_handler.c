#include "shell.h"

/**
 * getpath - uses the path to find executable files
 * @command: the file to be found
 * @program_name: receives the first main argument
 * Return: the full path to the executable
 */

char *getpath(const char *command)
{
	char *path = _getenv("PATH"), *full_path, *full_path_copy, *path_copy, *token, *copy;
	size_t path_len;

	if (path == NULL)
	{
		perror("PATH environment variable not set.");
		return (NULL);
	}

	path_copy = _strdup(path);
	if (is_malloc(path_copy))
		return (NULL);
	token = strtok(path_copy, ":");
	while (token && command)
	{
		path_len = (_strlen(token) + 1) + (_strlen(command) + 1);
		full_path = (char *)malloc(path_len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		full_path_copy = get_full_path(command, token);
		_strcpy(full_path, full_path_copy);
		free(full_path_copy);
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	if (command  == NULL)
		return (NULL);
	free(path_copy);
	copy = _strdup(command);
	return (copy);
}

/**
 * get_full_path - generates the full path
 * @command: the command to concatenated
 * @token: the PATH token
 * Return: the fullpath
 */

char *get_full_path(const char *command, char *token)
{
	size_t len = _strlen(token) + 1 + _strlen(command) + 1;
	char *fullpath = (char *)malloc(sizeof(char) * len);

	if (fullpath == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	_strcpy(fullpath, token);
	_strcat(fullpath, "/");
	_strcat(fullpath, command);
	
	return (fullpath);
}

#include "shell.h"

/**
 * find_executable - uses the path to find executable files
 * @filename: the file to be found
 * @program_name: receives the first main argument
 * Return: the full path to the executable
 */

char *getpath(const char *command, char *program_name)
{
	char *full_path, *full_path_copy, *path_copy, *token;
	size_t path_len;
	if (path == NULL)
	{
		perror("PATH environment variable not set.");
		return NULL;
	}
	path_copy = strdup(path);
	if (is_malloc(path_copy))
		return (NULL);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
        path_len = strlen(token) + 1 + strlen(command) + 1;
        full_path = (char *)malloc(path_len);
        if (is_malloc(full_path))
	{
            free(path_copy);
            return NULL;
        }
	full_path_copy = get_full_path(command, token);
	strcpy(full_path, full_path_copy);
	free(full_path_copy);
        if (access(full_path, X_OK) == 0)
	{
            free(path_copy);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    print(program_name);
    print(": No such file or directory\n");
    free(path_copy);
    return NULL;
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

	_strcpy(fullpath, token);
	_strcat(fullpath, "/");
	_strcat(fullpath, command);

	return (fullpath);
}

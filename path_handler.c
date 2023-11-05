#include "shell.h"

/**
 * find_executable - uses the path to find executable files
 * @filename: the file to be found
 * @program_name: receives the first main argument
 * Return: the full path to the executable

char *getpath(const char *filename, char *program_name)
{
	char *path = getenv("PATH");
	char *token = NULL, *error;
	char fullpath[128];
	size_t token_len;

	if (path == NULL)
	{
		perror("PATH environment variable is not set");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");

	
	while (token != NULL)
	{
		strcpy(fullpath, token);
		token_len = strlen(token);
		if (fullpath[token_len - 1] != '/')
		{
			strcat(fullpath, "/");
			token_len++;
		}
		strcat(fullpath, filename);
		if (access(fullpath, F_OK) != -1)
		{

			return (strdup(fullpath));
		}

		token = strtok(NULL, ":");
	}
	if (access(fullpath, F_OK) == -1)
	{
		error = strcat(program_name, ": No such file or directory");
		perror(error);
	}

	return (NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *find_command_path(const char *command) {
    char *path = getenv("PATH");
    char *full_path;
    size_t path_len;
    char *path_copy;
    char *token;

    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable is not set.\n");
        return NULL;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("Error");
        return NULL;
    }

    token = strtok(path_copy, ":");
    while (token != NULL) {
        path_len = strlen(token) + 1 + strlen(command) + 1;
        full_path = (char *)malloc(path_len);
        if (full_path == NULL) {
            perror("Error");
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, path_len, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
*/

char *find_command_path(const char *command) {
    char *path = getenv("PATH");
    char *full_path;
     char *path_copy;
     char *token;
     size_t path_len;

    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable is not set.\n");
        return NULL;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("Error");
        return NULL;
    }

    token = strtok(path_copy, ":");
    while (token != NULL) {
        path_len = strlen(token) + 1 + strlen(command) + 1;
        full_path = (char *)malloc(path_len);
        if (full_path == NULL) {
            perror("Error");
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, path_len, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

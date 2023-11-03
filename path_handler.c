#include "shell.h"

/**
 * find_executable - uses the path to find executable files
 * @filename: the file to be found
 * @program_name: receives the first main argument
 * Return: the full path to the executable
 */

char *getpath(const char *filename, char *program_name)
{
	char *path = getenv("PATH");
	char *token = NULL;
	char *fullpath = NULL;
	char *result = NULL, *dup_filename = NULL;
	size_t path_size = 1024, token_len;

	if (path == NULL)
	{
		perror("PATH environment variable is not set");
		exit(EXIT_FAILURE);
	}

	fullpath = (char *)malloc(path_size);
	if (fullpath == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");

	while (token != NULL)
	{
		strcpy(fullpath, token);
		token_len = strlen(token);
		if (fullpath[token_len - 1] != '/')
		{
			fullpath[token_len] = '/';
			token_len++;
		}
		dup_filename = strdup(filename);

		if (dup_filename == NULL)
		{
			perror("Memory allocation error");
			free(fullpath);
			exit(EXIT_FAILURE);
		}

		strcpy(fullpath + token_len, dup_filename);

		free(dup_filename);

		if (access(fullpath, F_OK) != -1)
		{
			result = strdup(fullpath);

			if (result == NULL)
			{
				perror("Memory allocation error");
				free(fullpath);
				exit(EXIT_FAILURE);
			}

			free(fullpath);
			return result;
		}

		token = strtok(NULL, ":");
	}

	free(fullpath);
	fprintf(stderr, "%s: No such file or directory\n", program_name);
	return NULL;
}

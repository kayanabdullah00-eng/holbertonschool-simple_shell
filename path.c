#include "shell.h"

/**
 * _getenv - Gets an environment variable
 * @name: Variable name
 *
 * Return: Value of variable or NULL
 */
char *_getenv(char *name)
{
	int i = 0;
	size_t len;

	len = strlen(name);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

/**
 * find_path - Finds a command in PATH
 * @command: Command name
 *
 * Return: Full path or NULL
 */
char *find_path(char *command)
{
	char *path, *copy, *dir, *full;
	int len;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	copy = strdup(path);
	if (copy == NULL)
		return (NULL);

	dir = strtok(copy, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + strlen(command) + 2;
		full = malloc(sizeof(char) * len);
		if (full == NULL)
		{
			free(copy);
			return (NULL);
		}

		strcpy(full, dir);
		strcat(full, "/");
		strcat(full, command);

		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}

		free(full);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}

#include "shell.h"

/**
 * tokenize - splits a string into tokens
 * @line: the input line
 *
 * Return: array of strings, or NULL on failure
 */
char **tokenize(char *line)
{
	char **args;
	char *token;
	int i;

	i = 0;
	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}

/**
 * main - entry point for simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	size_t len;
	ssize_t nread;
	char **args;

	line = NULL;
	len = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(0);
		}
		args = tokenize(line);
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(line);
			exit(0);
		}
		execute(args);
		free(args);
	}
	free(line);
	return (0);
}

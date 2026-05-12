#include "shell.h"
#include <string.h>

/**
 * main - simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char *cmd;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;
	char *argv[3];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		cmd = strtok(line, " \t");
		if (cmd == NULL)
			continue;

		argv[0] = cmd;
		argv[1] = strtok(NULL, " \t");
		argv[2] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		if (pid == 0)
		{
			execve(cmd, argv, environ);
			perror("./hsh");
			exit(127);
		}

		wait(&status);
	}

	free(line);
	return (0);
}

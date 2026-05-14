#include "shell.h"

/**
 * execute_cmd - Executes a command
 * @args: Command arguments
 * @program: Program name
 * @count: Command count
 *
 * Return: 0 on success, -1 on failure
 */
int execute_cmd(char **args, char *program, int count)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = find_path(args[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", program, count, args[0]);
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		free(cmd_path);
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			free(cmd_path);
			exit(127);
		}
	}

	wait(&status);
	free(cmd_path);
	return (0);
}

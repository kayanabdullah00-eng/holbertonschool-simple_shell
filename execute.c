#include "shell.h"

/**
 * execute - forks and executes a command
 * @args: array of arguments, NULL-terminated
 * @prog: name of the program (argv[0])
 *
 * Return: exit status of command
 */
int execute(char **args, char *prog)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = find_in_path(args[0]);
	if (cmd == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog, args[0]);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror("execve");
			free(cmd);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}

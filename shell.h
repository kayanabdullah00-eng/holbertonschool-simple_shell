#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

char **parse_line(char *line);
char *_getenv(char *name);
char *build_path(char *dir, char *command);
char *find_path(char *command);
int execute_cmd(char **args, char *program, int count);

#endif

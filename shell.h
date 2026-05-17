#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* main.c */
int main(void);

/* execute.c */
int execute(char **args);

/* path.c */
char *find_in_path(char *cmd);
char *_getenv(char *name);

#endif /* SHELL_H */

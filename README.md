# Simple Shell

## Description
Simple Shell is a basic UNIX command line interpreter written in C.

It reads a command from the user, splits it into arguments, creates a child process, and executes the command using `execve`.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

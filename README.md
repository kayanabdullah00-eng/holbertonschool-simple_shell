# Simple Shell

## Description

Simple Shell is a UNIX command line interpreter written in C.

This project recreates a basic shell that can execute commands entered by the user in both interactive and non-interactive modes.

The shell reads commands from standard input, parses them into arguments, creates child processes using `fork`, and executes commands using `execve`.

---

## Features

- Interactive shell mode
- Non-interactive shell mode
- Execute commands using `execve`
- Handle command arguments
- Handle the PATH environment variable
- Built-in `exit` command
- Built-in `env` command
- Error handling
- EOF handling (Ctrl + D)

---

## Learning Objectives

This project helped us understand:

- How a UNIX shell works
- Process creation and management
- The use of `fork`, `execve`, and `wait`
- Environment variables and PATH handling
- Interactive and non-interactive modes
- System calls and memory management

---

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- Betty coding style

Compilation flags:

```bash
-Wall -Werror -Wextra -pedantic -std=gnu89
```

---

## Compilation

Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

### Interactive mode

```bash
./hsh
```

Example:

```bash
($) /bin/ls
main.c shell.h README.md
($)
```

### Non-interactive mode

```bash
echo "/bin/ls" | ./hsh
```

Example:

```bash
main.c shell.h README.md
```

---

## Allowed Functions

Some allowed functions used in this project:

- fork
- execve
- wait
- waitpid
- getline
- strtok
- malloc
- free
- perror
- write
- access

---

## Files

| File | Description |
|------|-------------|
| main.c | Main shell program |
| shell.h | Header file |
| README.md | Project documentation |
| man_1_simple_shell | Shell manual |
| AUTHORS | Contributors list |

---

## Betty Style

This project follows the Betty coding style.

To check:

```bash
betty *.c *.h
```

---

## Authors

- Kayan Abdullah
- Saad Alatar

#include "shell.h"
/**
 * its_builtin - is building func
 * @command: cmd
 * Return: 0 Always (success).
*/
int its_builtin(char *command)
{
	char *builtinz[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int j;

	for (j = 0; builtinz[j]; j++)
	{
		if (_strcmp(command, builtinz[j]) == 0)
			return (1);
	}
	return (0);
}
/**
 * builtin_handle - handle buildin
 * @argv: arguments
 * @command: cmd
 * @st: status
 * @idx: index
 * Return: 0 Always (success).
*/
void builtin_handle(char **command, char **argv, int *st, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, st, idx);
	else if (_strcmp(command[0], "env") == 0)
		env_print(command, st);
}
/**
 * exit_shell - exit_shell
 * @argv: arguments
 * @command: cmd
 * @st: status
 * @idx: index
 * Return: 0 Always (success).
*/
void exit_shell(char **command, char **argv, int *st, int idx)
{
	int exit_value = (*st);
	char *index, msg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (is_p_num(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freeArrayToD(command);
			(*st) = 2;
			return;
		}
	}
	freeArrayToD(command);
	exit(exit_value);
}
/**
 * env_print - env_print
 * @command: cmd
 * @st: status
 * Return: 0 Always (success).
*/
void env_print(char **command, int *st)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeArrayToD(command);
	(*st) = 0;
}

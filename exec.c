#include "shell.h"
/**
 * _exec - excute cmds
 * @command: command
 * @argv: arguments
 * @idx: index
 * Return: 0 Always (success).
*/
int _exec(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getPath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		freeArrayToD(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			freeArrayToD(command);
			free(full_cmd), full_cmd = NULL;
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freeArrayToD(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}

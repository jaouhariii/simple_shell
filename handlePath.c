#include "shell.h"
/**
 * *_getPath - _getPath
 * @cmd: command
 * Return: 0 Always (success).
*/
char *_getPath(char *cmd)
{
	char *path_env, *full_cmd, *dir;
	int a;
	struct stat st;

	for (a = 0; cmd[a]; a++)
	{
		if (cmd[a] == '/')
		{
			if (stat(cmd, &st) == 0)
			return (_strdup(cmd));
		return (NULL);
		}
	}
	path_env = _getEn("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}


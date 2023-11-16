#include "shell.h"
/**
 * *_getEn - _getEn
 * @var: variable
 * Return: 0 Always (success).
*/
char *_getEn(char *var)
{
char *tmp, *key, *value, *env;
int a;

for (a = 0; environ[a]; a++)
{
tmp = _strdup(environ[a]);
key = strtok(tmp, "=");
if (_strcmp(key, var) == 0)
{
value = strtok(NULL, "\n");
env = _strdup(value);
free (tmp);
return (env);
}
free(tmp), tmp = NULL;
}
return (NULL);
}

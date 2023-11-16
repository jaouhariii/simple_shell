#include "shell.h"
/**
 * freeArrayToD - freeing array
 * @array: array to be freed
 * Return: 0 Always (success).
*/

void freeArrayToD(char **array)
{
	int a;

	if (!array)
		return;
	for (a = 0; array[a]; a++)
	{
		free(array[a]);
		array[a] = NULL;
	}
	free(array), array = NULL;
}
/**
 * print_error - print error
 * @name: name
 * @cmd: command
 * @idx: the index
 * Return: 0 Always (success).
*/

void print_error(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(index);
}
/**
 * *_itoa - integer conversion
 * @n: the int to be converted
 * Return: 0 Always (success).
*/

char *_itoa(int n)
{
	char buffer[20];
	int a = 0;

	if (n == 0)
		buffer[a++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[a++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[a] = '\0';
	reverse_string(buffer, a);
	return (_strdup(buffer));
}
/**
 * reverse_string - string reversion
 * @str: string
 * @len: length
 * Return: 0 Always (success).
*/
void reverse_string(char *str, int len)
{
	char temporary;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		temporary = str[start];
		str[start] = str[end];
		str[end] = temporary;
		start++;
		end--;
	}
}

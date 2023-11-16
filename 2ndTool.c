#include "shell.h"
/**
 * is_p_num - is it a positive number
 * @str: the string
 * Return: 0 Always (success).
*/
int is_p_num(char *str)
{
	int j;

	if (!str)
		return (0);
	for (j = 0; str[j]; j++)
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
	}
	return (1);
}
/**
 * *_atoi - a to int
 * @str: string to be converted
 * Return: 0 Always (success).
*/
int _atoi(char *str)
{
	int a, num = 0;

	for (a = 0; str[a]; a++)
	{
		num *= 10;
		num += (str[a] - '0');
	}
	return (num);
}

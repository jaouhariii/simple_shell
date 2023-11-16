#include "shell.h"
/**
 * *_strdup - string dup
 * @str: string
 * Return: 0 Always (success).
*/
char *_strdup(const char *str)
{
	char *ptr;
	int a, length = 0;

	if (str == NULL)
		return (NULL);
	while (str[length])
		length++;
	ptr = malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (NULL);
	for (a = 0; a <= length; a++)
		ptr[a] = str[a];
	return (ptr);
}
/**
 * _strcmp - string compare
 * @s1: string1
 * @s2: string2
 * Return: 0 Always (success).
*/
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
/**
 * _strlen - string length
 * @s: string
 * Return: 0 Always (success).
*/
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}
/**
 * *_strcat - string cat
 * @src: source
 * @dest: destination
 * Return: 0 Always (success).
*/
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}
/**
 * *_strcpy - string copy
 * @src: source
 * @dest: destination
 * Return: 0 Always (success).
*/
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

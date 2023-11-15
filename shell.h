#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *examin_line(void);
char **theTokenizer(char *line);
int _exec(char **command, char **argv, int idx);



/* string.C */
int _strlen (char *s);
char *_strdup(const char *str);
int _strcmp (char *s1, char *s2);
char _strcat(char *dest, char *src);
char *_strcpy (char *dest, char *src);

/* tools.C */
void freeArrayToD(char **array);
void print_err(char *name, char *cmd, int idx); 
char *_itoa(int n);
void string_rev(char *str, int len);

#endif


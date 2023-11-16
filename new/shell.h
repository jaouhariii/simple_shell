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

char *_getEn(char *var);
char *_getPath(char *cmd);

/* builtinz */
int its_builtin(char *command);
void builtin_handle(char **command, char **argv, int *st, int idx);
void exit_shell(char **command, char **argv, int *st, int idx);
void env_print(char **command, int *st);

/* strings */
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* tools */
void freeArrayToD(char **array);
void print_error(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);

#endif

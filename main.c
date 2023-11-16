#include "shell.h"
/**
 * main - The Simple Shell main entry point func
 * @ac: Count of argumnents
 * @argv: Arguments
 * Return: 0 Always (success).
*/
int main(int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int st = 0, idx = 0;
    (void) ac;

    while (true)
    {
        line = examin_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (st);
        }
        idx++;
        command = theTokenizer(line);
        if (!command)
        continue;
        if (its_builtin(command[0]))
            builtin_handle(command, argv, &st, idx);

        else
            st = _exec(command, argv, idx);
    }
}

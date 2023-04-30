#include "main.h"
/**
 * cd - changes directory
 * @dir: directory
 * Return: nothing
 */
void cd(char *dir)
{
#define MAX_PATH_LEN 4096
    char path[MAX_PATH_LEN];
    char cwd[BUFFER_SIZE];
    char *home_dir = getenv("HOME");

    if (dir == NULL || strcmp(dir, "~") == 0)
    {
        dir = home_dir;
    }
    else if (strcmp(dir, "-") == 0)
    {
        dir = getenv("OLDPWD");
    }

    if (getcwd(path, MAX_PATH_LEN) == NULL)
    {
        perror("Error: getcwd failed");
        return;
    }
    if (chdir(dir) == -1)
    {
        perror("Error: chdir failed");
        return;
    }

    if (setenv("OLDPWD", cwd, 1) == -1)
    {
        perror("Error: setenv failed");
        return;
    }

    if (setenv("PWD", dir, 1) == -1)
    {
        perror("Error: setenv failed");
        return;
    }
}

#include "main.h"
#include <libgen.h>

/**
 * cd - changes directory
 * @dir: directory
 * Return: nothing
 */
void cd(char *dir)
{
	char cwd[1024];
	char *directname;
	char *dirpath;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return;
	}
	if (chdir(dir) == -1)
	{
		perror("chdir() error");
		return;
	}
	directname = strdup(dir);
	dirpath = directname;
	if (directname != NULL)
	{
		dirpath = dirname(directname);
		if (chdir(dirpath) == -1)
		{
			perror("chdir() error");
			free(directname);
			return;
		}
		free(directname);
	}
	if (setenv("OLDPWD", cwd, 1) == -1)
	{
		perror("setenv() error");
		return;
	}
	if (setenv("PWD", getcwd(cwd, sizeof(cwd)), 1) == -1)
	{
		perror("setenv() error");
		return;
	}
}
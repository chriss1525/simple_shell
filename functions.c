#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "main.h"

/**
 * getting ppid of a process
 */

int main(__attribute__((unused))int ac, char **av)
{
	pid_t my_pid;
	pid_t my_ppid;
	int i;

	for (i = 0; *(av + i) != NULL; i++)
	{
		printf("%s\n", *(av + i));
	}

	my_pid = getpid();
	my_ppid = getppid();

	printf("%d\n", my_pid);
	printf("%d\n", my_ppid);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - takes in command from stdin and executes the command
 * Return: 0 (success)
 */

#define BUFFER_SIZE 1024

int main(void)
{
	char input[BUFFER_SIZE];
	char *command;
	char *newline;
	char *args[] = {command, NULL};

	extern char **environ;

	char *my_env[] = {
		"HOME=/home/user",
		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
		NULL};

	environ = my_env;

	while (1)
	{
		/* Display prompt in parent process */
		if (getpid() == getpgrp())
			_printf("> ");

		/* Wait for user input */
		if (fgets(input, BUFFER_SIZE, stdin) == NULL)
		{
			_printf("\n");
			exit(0);
		}

		/* Check for EOF (Ctrl+D) */
		if (feof(stdin))
		{
			_printf("\n");
			exit(0);
		}

		/* Strip newline character */
		newline = strchr(input, '\n');
		if (newline != NULL)
		{
			*newline = '\0';
		}

		/* Remove trailing newline */
		input[strcspn(input, "\n")] = '\0';

		/* Trim leading/trailing whitespace */
		command = strtok(input, " \n\t\r");

		/* Execute command */
		if (command != NULL)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("Error: fork failed");
				exit(1);
			}

			if (pid == 0)
			{
				/* Child process */
				if (execve(command, args, environ) == -1)
				{
					_printf("Error: Command not found.\n");
					exit(1);
				}
			}
			else
			{
				/* Parent process */
				int status;
				waitpid(pid, &status, 0);
			}
		}
	}

	return (0);
}

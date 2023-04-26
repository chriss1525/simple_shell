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
	char **args;
	char *newline;
	char *token;
	int i;
	pid_t pid;

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
		token = strtok(input, " \n\t\r");

		/* Tokenize input into arguments */
		args = malloc(sizeof(char *));
		i = 0;
		while (token != NULL)
		{
			args = realloc(args, sizeof(char *) * (i + 2));
			args[i] = token;
			token = strtok(NULL, " \n\t\r");
			i++;
		}
		args[i] = NULL;

		/* Execute command */
		if (args[0] != NULL)
		{
			pid = fork();

			if (pid == -1)
			{
				perror("Error: fork failed");
				exit(1);
			}
			else if (pid == 0)
			{
				/* Child process */
				if (execvp(args[0], args) == -1)
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

			free(args);
			args = NULL;
		}
	}

	return 0;
}

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

int main(void)
{
	char input[BUFFER_SIZE];
	char **args;
	pid_t pid;

	signal(SIGKILL, sigint_handler);

	while (1)
	{
		/* Display prompt in parent process */
		if (getpid() == getpgrp())
		{
			write(STDOUT_FILENO, "> ", 2);
			fflush(stdout);
		}

		/* Wait for user input */
		if (fgets(input, BUFFER_SIZE, stdin) == NULL || input[0] == '\n')
		{
			exit(0);
			continue;
		}

		/*Remove newline character from input*/
		input[strcspn(input, "\n")] = '\0';

		/* Check for EOF (Ctrl+D) */
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 2);
			exit(0);
		}

		/* Check for exit command */
		if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0 || input[0] == '\n')
		{
			exit(0);
			continue;
		}

		/* Check for cd command */
		if (strncmp(input, "cd", 2) == 0)
		{
			/* Tokenize input into arguments */
			args = parse_input(input);

			/* Handle cd command */
			cd(args[1]);

			free(args);
			continue;
		}

		/* Tokenize input into arguments */
		args = parse_input(input);

		/* Execute command */
		if (args[0] != NULL && args[0][0] != '\0')
		{
			pid = fork();

			if (pid == -1)
			{
				perror("Error: fork failed");
				exit(0);
			}
			else if (pid == 0)
			{
				/* Child process */
				if (execvp(args[0], args) == -1)
				{
					_printf("Error: Command not found.\n");
					exit(0);
				}
			}
			else
			{
				/* Parent process */
				int status;
				waitpid(pid, &status, 0);
			}

			free(args);
		}
	}

	return (0);
}

/**
 * parse_input - breaks arguments to tokens
 * @input: user input
 * Return: arguments passed
 */
#define MAX_ARGS 64
char **parse_input(char *input)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token = strtok(input, " \n\t\r");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n\t\r");
		;
	}
	args[i] = NULL;
	return (args);
}

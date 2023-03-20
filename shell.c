#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - takes in command from stdin and executes the command
 * Return: 0 (success)
 */

#define BUFFER_SIZE 1024

int main()
{
	char input[BUFFER_SIZE];
	char *command;

	while (1)
	{
		/*Display prompt*/
		printf("> ");

		/*Wait for user input*/
		if (fgets(input, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}

		/*Check for EOF (Ctrl+D)*/
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}

		/*Trim leading/trailing whitespace*/
		command = strtok(input, " \n\t\r");

		// Execute command
		if (command != NULL)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(1);
			}
			else if (pid == 0)
			{
				// Child process
				if (execlp(command, command, NULL) == -1)
				{
					printf("Error: Command not found.\n");
				}
				exit(0);
			}
			else
			{
				// Parent process
				int status;
				waitpid(pid, &status, 0);
			}
		}
	}

	return 0;
}

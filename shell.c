#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

		/*Trim leading/trailing whitespace*/
		command = strtok(input, " \n\t\r");

		/*Execute command*/
		if (command != NULL)
		{
			if (execlp(command, command, NULL) == -1)
			{
				printf("Error: Command not found.\n");
			}
		}
	}

	return 0;
}

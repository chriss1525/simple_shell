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

#define BUFFER_SIZE 20

int main(void)
{
    char input[BUFFER_SIZE];
    char **args;
    /*char *newline;*/
    char *token;
    int i;
    pid_t pid;
    /*int len;*/

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

        /* Strip newline character*/

        /*len = strcspn(input, "\n");
        if (len < BUFFER_SIZE)
        {
            memset(input + len, '\0', 1);
        }*/
        /*newline = strchr(input, '\n');
        if (newline != NULL)
        {
            *newline = '\0';
        }*/

        /* Remove trailing newline */
        /*input[strcspn(input, "\n")] = '\0';*/

        /* Tokenize input into arguments */
        token = strtok(input, " \n\t\r");

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
        if (args[0] != NULL && args[0][0] != '\0')
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
            /*args = NULL;*/
        }

        /* Check if last character of input is newline character */
        /*if (input[strlen(input) - 1] == '\n') {
            _printf("\b");
        }*/
    }

    return 0;
}

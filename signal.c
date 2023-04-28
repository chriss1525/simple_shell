#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
/**
 * sigint_handler - handles end signal
 * @sig: the signal
 *
 * Return: nothing
 */
void sigint_handler(int sig)
{
	printf("Received signal %d\n", sig);
	exit(EXIT_FAILURE);
}
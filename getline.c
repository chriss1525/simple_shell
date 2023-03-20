#include "main.h"
/**
 * main - prints $ and an input
 * Return: int
 */
int main()
{
    char *buffer;
    size_t buffsize;
    ssize_t buff_read;

    buffer = NULL;
    buffsize = 0;

    printf("$ ");
    buff_read = getline(&buffer, &buffsize, stdin);
    if (buff_read != -1)
    {
        printf("%s", buffer);
    }
    
    free(buffer);
    return (0);
}

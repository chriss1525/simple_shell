#include "main.h"
/**
 * 
*/
int main()
{
    char *buffer;
    size_t buffsize;
    
    buffer = malloc(sizeof(size_t));
    /*size_t characters;*/
    printf("$ ");
    getline(&buffer, &buffsize, stdin);
    printf("%s", buffer);
    return (0);
}

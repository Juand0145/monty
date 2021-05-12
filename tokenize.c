#include "monty.h"

char **tokenize(char *command_line)
{
    int size = _strlen(command_line);
    char *token;
    char **arguments_token = malloc(sizeof(char *) * size);
    int i;
    
    if (!arguments_token)
    {
        perror("error args");
        exit(EXIT_FAILURE);
    }

    token = strtok(command_line, " \n");

    for (i = 0; token != NULL; i++)
    {
    arguments_token[i] = token;
    token = strtok(NULL, " \n");
    }

    return (arguments_token);    
}
#include "monty.h"

/**
* tokenize - function to save line in the array pointer
* @arguments: arguments for line in the file
*
*
* Return: array pointers
*/

char **tokenize(char *arguments)
{
	char *line;
	char **commands = malloc(sizeof(char *) * _strlen(arguments));
	int i = 0;

	line = strtok(arguments, " \t\r\n");
	while (line != NULL)
	{
		commands[i] = line;
		i++;
		line = strtok(NULL, " \t\n");
	}
	commands[i] = NULL;
	return (commands);
}

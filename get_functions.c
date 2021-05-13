#include "monty.h"

/**
 * get_function - a function to search functions
 * @command: a list of commands
 * Return: a pointer to the fuction
 */
void (*get_function(char **command))(stack_t **, unsigned int)
{
	instruction_t function_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
	};

	int codes = 8, i;

	if (command == NULL)
		return (NULL);

	for (i = 0; i < codes; i++)
	{
		if (strcmp(function_list[i].opcode, command[0]) == 0)
		{
			return (function_list[i].f);
		}
	}
	return (NULL);
}

#include "monty.h"

/**
* read_files - function that open and read of the content of the file
* @file_name: pointer to name file
*
* Return: void
*/

void read_files(char *file_name)
{
	stack_t *head = NULL;
	FILE *pfile;
	char *line;
	size_t len = 0;
	char **command;

	pfile = fopen(file_name, "r");
	if (!pfile)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, pfile) != -1)
	{
		count_line++, command = tokenize(line);
		if (_strcmp(command[0], "push") == 0)
			push(&head, atoi(command[1]));
		else if (_strcmp(command[0], "pall") == 0)
			pall(head);
		else if (_strcmp(command[0], "pint") == 0)
			pint(head);
		else if (_strcmp(command[0], "pop") == 0)
			pop(&head);
		else if (_strcmp(command[0], "swap") == 0)
			swap(&head);
		else if (_strcmp(command[0], "add") == 0)
			add(&head, count_line);
		else if (_strcmp(command[0], "nop") == 0)
			nop();
		else if (_strcmp(command[0], "sub") == 0)
			sub(&head, count_line);
		else
		{
			if (command[0] != NULL)
			{
				dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
				count_line, command[0]);
				free(command), fclose(pfile), free_list(head), free(line);
				exit(EXIT_FAILURE);
			}
		}
		free(command);
	}
	fclose(pfile), free(line), free_list(head);
}

/**
* _strlen - function that return len of the string
* @s: pointer to string
*
* Return: lenght of the string
*/

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
* _strcmp - function that compare two strings
* @s1: pointer to string1
* @s2: pointer to strign2
*
* Return: 0 in case of the strings equals or -1 in case failure
*/


int _strcmp(char *s1, char *s2)
{
	int l1 = 0;
	int l2 = 0;
	int i = 0;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 == 0 || l2 == 0)
		return (-1);
	while (*(s1 + i) == *(s2 + i))
		i++;
	i--;
	if (l1 == i && l2 == i)
		return (0);
	return (-1);
}

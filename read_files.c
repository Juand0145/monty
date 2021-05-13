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
	void (*exec_function)(stack_t **, unsigned int);


	pfile = fopen(file_name, "r");
	if (!pfile)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	data.count_line = 0;
	while (getline(&line, &len, pfile) != -1)
	{
		data.count_line++,
		data.commands = tokenize(line);

		if (data.commands[0])
			exec_function = get_function(data.commands);

		if (exec_function == NULL && data.commands[0] != NULL)
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
			data.count_line, data.commands[0]);
			free(data.commands), fclose(pfile), free_list(head), free(line);
			exit(EXIT_FAILURE);
		}

		exec_function(&head, data.count_line);
		free(data.commands);
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

#include "monty.h"

/**
 * push - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void push(stack_t **head, unsigned int line)
{
	if (_atoi_verify(data.commands[1]) == -1 || data.commands[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	add_dnodeint(head, atoi(data.commands[1]));
}

/**
 * pall - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void pall(stack_t **head, unsigned int line)
{
	if (!head || line)
		print_dlistint(*head);
}

/**
 * pint - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void pint(stack_t **head, unsigned int line)
{
	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void pop(stack_t **head, unsigned int line)
{
	_pop(head);

	if (!(head))
		printf("%d", line);
}

/**
 * swap - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void swap(stack_t **head, unsigned int line)
{
	_swap(head);

	if (!(head))
		printf("%d", line);
}

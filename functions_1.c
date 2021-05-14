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
	if (*head == NULL)
		_nop();
	else if (!head || line)
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
	if (*head == NULL || head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
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
	if (*head == NULL || head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	_pop(head);
}

/**
 * swap - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;

	if (tmp->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	_swap(head);
}

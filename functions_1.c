#include "monty.h"

/**
 * push - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void push(stack_t **head, unsigned int line)
{
	add_dnodeint(head, atoi(data.commands[1]));

	if (!(head))
		printf("%d", line);
}

/**
 * pall - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void pall(stack_t **head, unsigned int line)
{
	print_dlistint(*head);

	if (!(head))
		printf("%d", line);

}

/**
 * pint - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void pint(stack_t **head, unsigned int line)
{
	printf("%d\n", (*head)->n);

	if (!(head))
		printf("%d", line);
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

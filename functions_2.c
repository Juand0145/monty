#include "monty.h"

/**
 * nop - a function that adds a new node at the
 * @head: A pointer to the direction of the head of teh list
 * @line: the integer value of the node
 * Return: void
 */
void nop(stack_t **head, unsigned int line)
{
	_nop();

	if (!(head))
		printf("%d", line);
}

/**
* sub - subtracts the top element of the stack from the second top
* element of the stack.
* @head: double pointer indicated a head of the linked_list
* @count_line: integer indicated line of the file
*
* Return: void
*/
void sub(stack_t **head, unsigned int count_line)
{
	stack_t *tmp;
	stack_t *tmp2;
	stack_t *tmpfree;

	if (*head == NULL || head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n",
		count_line);
		exit(EXIT_FAILURE);
	}
	tmpfree = *head, tmp2 = NULL, tmp = NULL;
	if (tmpfree->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n",
		count_line);
		exit(EXIT_FAILURE);
	}
	tmp = tmpfree->next, tmp->n = tmp->n - tmpfree->n, *head = tmp;
	if (tmp->next != NULL)
	{
		tmp2 = tmp->next, tmp->next = tmp2, tmp2->prev = tmp;
	}
	else
	{
		tmp->next = NULL, tmp->prev = NULL;
	}
	tmpfree->next = NULL, tmpfree->prev = NULL;
	free(tmpfree);
}

/**
* add - adds the top two elements of the stack.
* @head: double pointer to inidcated the head of the linked list
* @count_line: integer is the line of the file
*
* Return: void
*/

void add(stack_t **head, unsigned int count_line)
{
	stack_t *tmp;
	stack_t *tmp2;
	stack_t *tmpfree;

	if (*head == NULL || head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n",
		count_line);
		exit(EXIT_FAILURE);
	}
	tmpfree = *head, tmp2 = NULL, tmp = NULL;
	if (tmpfree->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n",
		count_line);
		exit(EXIT_FAILURE);
	}
	tmp = tmpfree->next, tmp->n = tmp->n + tmpfree->n, *head = tmp;
	if (tmp->next != NULL)
	{
		tmp2 = tmp->next, tmp->next = tmp2, tmp2->prev = tmp;
	}
	else
	{
		tmp->next = NULL, tmp->prev = NULL;
	}
	tmpfree->next = NULL, tmpfree->prev = NULL;
	free(tmpfree);
}

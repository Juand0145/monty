#include "monty.h"

/**
* free_list - a function that frees a dlistint_t list.
* @head: the head of the list.
*
* Return: void
*/

void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

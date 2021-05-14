#include "monty.h"



/**
 * print_dlistint - is a function that prints all the elements of a
 * dlistint_t list.
 * @h: A pointer to the beginig of the list
 * Return: The number of elements in the list
 */
size_t print_dlistint(const stack_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		i++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (i);
}

/**
 * add_dnodeint - a function that adds a new node at the
 * beginning of a dlistint_t list.
 * @head: A pointer to the direction of the head of teh list
 * @n: the integer value of the node
 * Return: The new_node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * _pop -  a function that deletes the
 * node at index index of a dlistint_t linked list.
 * @head: the pointer to the direction of the list.
 * Return: 1 if it works or -1 if don't
 */
void _pop(stack_t **head)
{
	stack_t *temp = NULL;
	stack_t *current = *head;

	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		temp = (*head)->next;
		*head = temp;
		temp->prev = NULL;
		free(current);
	}
}
/**
 * _swap -  a function that deletes the
 * node at index index of a dlistint_t linked list.
 * @head: the pointer to the direction of the list.
 * Return: 1 if it works or -1 if don't
 */
void _swap(stack_t **head)
{
	stack_t *node_a = NULL;
	stack_t *node_b = NULL;
	stack_t *current = *head;

	node_a = current->next;
	node_b = node_a->next;

	node_a->next = current;
	current->next = node_b;
	node_b->prev = current;
	current->prev = node_a;
	node_a->prev = NULL;

	*head = node_a;
}

/**
* _nop - functions that made nothing
* Return: EXIT_SUCCESS
*/
int _nop(void)
{
	return (EXIT_SUCCESS);
}

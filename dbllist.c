#include "monty.h"

/**
 * add_node_beg - add a new node at the beginning of a stack
 * @head: pointer to the stack
 * @n: data to be inserted
 *
 * Return: a pointer to a stack or NULL if it failed
 */
stack_t *add_node_beg(stack_t **head, const int n)
{
	stack_t *beg;

	if (head == NULL)
		return (NULL);
	beg = malloc(sizeof(stack_t));
	if (!beg)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	beg->n = n;
	beg->next = *head;
	if (*head)
		(*head)->prev = beg;
	beg->prev = NULL;
	*head = beg;
	return (*head);
}

/**
 * add_node_end - add a new node at the end of a stack
 * @head: pointer to the pointer of the head of the stack
 * @n: data to be inserted
 *
 * Return: a pointer to the stack or NULL if failed
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *end, *new;

	if (head == NULL)
		return (NULL);
	end = malloc(sizeof(stack_t));
	if (!end)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeVar();
		exit(EXIT_FAILURE);
	}
	end->n = n;
	end->next = NULL;
	if (*head == NULL)
	{
		end->prev = NULL;
		*head = end;
		return (*head);
	}
	new = *head;
	while (new->next != NULL)
		new = new->next;
	new->next = end;
	end->prev = new;
	return (end);
}

/**
 * free_stack - free a stack
 * @head: pointer to a node
 *
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *new;

	while ((new = head) != NULL)
	{
		head = head->next;
		free(new);
	}
}

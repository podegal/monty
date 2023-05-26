#include "monty.h"

/**
 * op_swap - a fxn that swaps the top two elements of the stack
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_swap(stack_t **head, unsigned int linenum)
{
	stack_t *new;
	unsigned int j = 0;

	new = *head;
	while (new)
	{
		j++;
		new = new->next;
	}
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	new = *head;
	*head = (*head)->next;
	new->next = (*head)->next;
	new->prev = (*head);
	(*head)->next = new;
	(*head)->prev = NULL;
}

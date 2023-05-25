#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @head: pointer to to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_pop(stack_t **head, unsigned int linenum)
{
	stack_t *new;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	new = *head;
	*head = (*head)->next;
	free(new);
}

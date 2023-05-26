#include "monty.h"

/**
 * op_add - a fxn that adds the elements
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_add(stack_t **head, unsigned int linenum)
{
	stack_t *temp;
	unsigned int j = 0;

	temp = *head;
	while (temp)
	{
		j++;
		temp = temp->next;
	}
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n += (*head)->n;
	op_pop(head, linenum);
}

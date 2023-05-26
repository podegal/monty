#include "monty.h"

/**
 * op_mod - computes the rest of the division of 2nd element by the 1st element
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_mod(stack_t **head, unsigned int linenum)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n %= (*head)->n;
	op_pop(head, linenum);
}

#include "monty.h"

/**
 * op_mul - divides the second top element of the stack by the top element
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_mul(stack_t **head, unsigned int linenum)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n *= (*head)->n;
	op_pop(head, linenum);
}

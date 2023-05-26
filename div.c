#include "monty.h"

/**
 * op_div - divides the second top element of the stack by the top element
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_div(stack_t **head, unsigned int linenum)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n /= (*head)->n;
	op_pop(head, linenum);
}

#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 */
void op_pint(stack_t **head, unsigned int linenum)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

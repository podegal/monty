#include "monty.h"

/**
 * op_pchar - prints the char at the top of the stack
 * @head: pointer to the pointer of the head of the stack
 * @linenum: the current line number
 *
 * Return: nothing
 */
void op_pchar(stack_t **head, unsigned int linenum)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

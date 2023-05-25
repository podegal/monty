#include "monty.h"

/**
 * op_pall - prints all data of a stack
 * @head: pointer to pointer to the head of the stackk
 * @linenum: curent line number
 *
 * Return: nothing
 */
void op_pall(stack_t **head, unsigned int linenum)
{
	stack_t *new;

	(void)linenum;
	new = *head;
	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

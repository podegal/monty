#include "monty.h"

/**
 * op_stack - a fxn that sets the format of the data to a stack
 * @head: pointer to pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_stack(stack_t **head, unsigned int linenum)
{
	(void)head;
	(void)linenum;

	glbVar.sq = 1;
}

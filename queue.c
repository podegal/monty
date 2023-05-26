#include "monty.h"

/**
 * op_queue - a fxn that sets the format of the data to a queue
 * @head: pointer to pointer to the head of the queue
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_queue(stack_t **head, unsigned int linenum)
{
	(void)head;
	(void)linenum;

	glbVar.sq = 0;
}

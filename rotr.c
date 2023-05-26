#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom.
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */

void op_rotr(stack_t **head, unsigned int linenum)
{
	stack_t *temp, *new;

	(void)linenum;

	if (*head && (*head)->next)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		new = temp->prev;
		new->next = NULL;
		temp->next = *head;
		(*head)->prev = temp;
		temp->prev = NULL;
		*head = temp;
	}
}

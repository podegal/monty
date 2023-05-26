#include "monty.h"

/**
 * op_rotl - rotates the stack to the top.
 * @head: pointer to the pointer to the head of the stack
 * @linenum: current line number
 *
 * Return: nothing
 */
void op_rotl(stack_t **head, unsigned int linenum)
{
	stack_t *new, *sec;

	(void)linenum;

	if (*head && (*head)->next)
	{
		new = *head;
		while (new->next)
			new = new->next;

		sec = (*head)->next;
		sec->prev = NULL;
		new->next = *head;
		(*head)->prev = new;
		(*head)->next = NULL;
		*head = sec;
	}
}

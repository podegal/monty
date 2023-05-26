#include "monty.h"

/**
 * op_pstr - prints the string at the top of the stack
 * @head: pointer to the pointer of the head of the stack
 * @linenum: the current line number
 *
 * Return: nothing
 */
void op_pstr(stack_t **head, unsigned int linenum)
{
	stack_t *temp;

	(void)linenum;
	temp = *head;
	while (temp && (temp->n > 0) && (temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

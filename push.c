#include "monty.h"

/**
 * op_push - pushes data to a stack
 * @head: pointer to the pointer the head of the stack
 * @linenum: current line number
 *
 */
void op_push(stack_t **head, unsigned int linenum)
{
	int n, i;

	if (!glbVar.instArg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", linenum);
		freeVar();
		exit(EXIT_FAILURE);
	}
	for (i = 0; glbVar.instArg[i] != '\0'; i++)
	{
		if (!isdigit(glbVar.instArg[i]) && glbVar.instArg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", linenum);
			freeVar();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(glbVar.instArg);
	if (glbVar.sq == 1)
		add_node_beg(head, n);
	else if (glbVar.sq == 0)
		add_node_end(head, n);
}

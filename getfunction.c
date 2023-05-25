#include "monty.h"

/**
 * getFunc - get the function associated to an instruction
 * @operatn: pointer to the operation
 *
 * Return: pointer to the funciton associated or NULL if not found
 */
void (*getFunc(char *operatn))(stack_t **stack, unsigned int line_number)
{
	instruction_t operation[] = {
		{"push", op_push}, {"pall", op_pall},
		{"pint", op_pint}, {"pop", op_pop},
		{NULL, NULL}
	};

	int i;

	for (i = 0; operation[i].opcode; i++)
	{
		if (strcmp(operation[i].opcode, operatn) == 0)
			break;
	}
	return (operation[i].f);
}

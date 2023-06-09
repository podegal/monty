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
		{"swap", op_swap}, {"add", op_add},
		{"nop", op_nop}, {"sub", op_sub},
		{"div", op_div}, {"mul", op_mul},
		{"mod", op_mod}, {"pchar", op_pchar},
		{"pstr", op_pstr}, {"rotl", op_rotl},
		{"stack", op_stack}, {"queue", op_queue},
		{"rotr", op_rotr}, {NULL, NULL}
	};

	int i;

	for (i = 0; operation[i].opcode; i++)
	{
		if (strcmp(operation[i].opcode, operatn) == 0)
			break;
	}
	return (operation[i].f);
}

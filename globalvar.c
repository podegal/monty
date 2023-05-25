#include "monty.h"

/**
 * initVar - initialize the global variable
 * @filedes: file descriptor of the opened file
 *
 * Return: nothing
 */
void initVar(FILE *filedes)
{
	glbVar.linenum = 1;
	glbVar.filedes = filedes;
	glbVar.head = NULL;
	glbVar.buffer = NULL;
	glbVar.instArg = NULL;
	glbVar.sq = 1;
}

/**
 * freeVar - free the global variable
 *
 * Return: nothing
 */
void freeVar(void)
{
	free_stack(glbVar.head);
	free(glbVar.buffer);
	fclose(glbVar.filedes);
}

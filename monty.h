#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - structure for the global variable
 * @linenum: current line  number
 * @filedes: file descriptor of the opened file
 * @head: pointer to the head of the stack
 * @buffer: buffer used to read the current line
 * @instArg: argument of the instruction
 * @sq: flag - 1 for stack and 0 for queue (default set to 1)
 *
 * Description: Global variable that will be shared on
 * source fileto hanlde instructions
 */
typedef struct data_s
{
	unsigned int linenum;
	FILE *filedes;
	stack_t *head;
	char *buffer;
	char *instArg;
	int sq;
} data_t;

extern data_t glbVar;

/* global variable functions */
void initVar(FILE *filedes);
void freeVar(void);

/* double linked list functions */
stack_t *add_node_beg(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
void free_stack(stack_t *head);

/* get function */
void (*getFunc(char *operatn))(stack_t **stack, unsigned int line_number);

/* getline function */
ssize_t getLine(char **lineptr, size_t *n, FILE *stream);

/* instructions functions */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);

#endif

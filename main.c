#include  "monty.h"

data_t glbVar;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *filedes;
	size_t size = 128;
	ssize_t no_of_char_read = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *first_token = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filedes = fopen(argv[1], "r");
	if (!filedes)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	initVar(filedes);
	no_of_char_read = getLine(&glbVar.buffer, &size, filedes);
	while (no_of_char_read != -1)
	{
		first_token = strtok(glbVar.buffer, " \t\n");
		if (first_token && first_token[0] != '#')
		{
			f = getFunc(first_token);
			if (!f)
			{
			fprintf(stderr, "L%u: ", glbVar.linenum);
			fprintf(stderr, "unknown instruction %s\n", first_token);
			freeVar();
			exit(EXIT_FAILURE);
			}
			glbVar.instArg = strtok(NULL, " \t\n");
			f(&glbVar.head, glbVar.linenum);
		}
		no_of_char_read = getLine(&glbVar.buffer, &size, filedes);
		glbVar.linenum++;
	}
	freeVar();
	return (0);
}

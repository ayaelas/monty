#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * hndle - function
 * @op : operator
 * @n : line number
 * @t : pointer
 * Return : function
 */
void (*hndle(char *op, unsigned int n, stack_t **t))(stack_t**, unsigned int)
{
	int i;
	instruction_t oper[] = {
		{"sub", sub},
		{"mod", mod},
		{"mul", mul},
		{"pall", pall},
		{"print_list", print_list},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}
	};
	for (i = 0; oper[i].opcode; i++)
	{
		if (strcmp(oper[i].opcode, op) == 0)
			return (oper[i].f);
	}

	fprintf(stderr, "L%u: unknown instructon %s\n", n, op);
	fclose(file);
	freee(*t);
	exit(EXIT_FAILURE);
}
/**
 * freee - function
 * @line : line
 */
void freee(stack_t *stack)
{
	stack_t *top;

	while (stack)
	{
		top = stack->next;
		free(stack);
		stack = top;
	}
}

/**
 * _isint - function
 * @str :string
 * Return 0 if true , 1 if false
 */
int _isint(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

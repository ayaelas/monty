#include "monty.h"
#include <stdio.h>

/**
 * hndle - functions
 * @op: operator
 * @n: line count
 * @t: pointer to the stack
 *
 * Return: the right function
*/
void (*hndle(char *op, unsigned int n, stack_t **t))(stack_t**, unsigned int)
{
	int i;
	instruction_t oper[] = {
		{"sub", sub},
		{"mod", mod},
		{"div", duv},
		{"mul", mul},
		{"pall", pall},
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

	fprintf(stderr, "L%u: unknown instruction %s\n", n, op);
	fclose(fd);
	freeze(*t);
	exit(EXIT_FAILURE);
}

/**
 * freeze - function
 * @stack : stack
 *
 * Return : void
 */
void freeze(stack_t *stack)
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
 * @str: the string
 *
 * Return: 1 true,0 false
*/
int _isint(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

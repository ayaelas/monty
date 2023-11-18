#include "monty.h"
/**
 * nop - function
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - function
 * @stack : stack
 * @line_number : line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(file);
		freee(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
}

/**
 * print_list - function
 * @s : stack
 * @line_number : line number
 */
void print_list(stack_t **s, unsigned int line_number)
{
	if (!*s)
	{
		fprintf(stderr, "L%u: can't print, stack empty\n", line_number);
		freee(*s);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if ((*s)->n > 127 || (*s)->n < 0)
	{
		fprintf(stderr, "L%u: can't print, out of range\n", line_number);
		freee(*s);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*s)->n);
}

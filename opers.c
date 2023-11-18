#include "monty.h"

/**
 * push - function
 * @stack : stack
 * @line_number : line number
 * @par : parameter
*/
void push(stack_t **stack, char *par, unsigned int line_number)
{
	stack_t *stck;
	(void) line_number;

	stck = malloc(sizeof(stack_t));
	if (par == NULL || _isint(par) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		freee(*stack);
		exit(EXIT_FAILURE);
	}
	if (!stck)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	stck->n = atoi(par);
	stck->next = *stack;
	stck->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = stck;
	(*stack) = stck;
}
/**
 * pall - function
 * @stack: stack
 * @line_number : line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;
	top = (*stack);

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
/**
 * pint - function
 * @stack :stack
 * @line_number : line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
	printf("%d\n", (*stack)->n);
}
/**
 * pop - function
 * @stack : stack
 * @line_number : line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->next;
	free(*stack);

	if (top)
		top->prev = NULL;
	*stack = top;
}
/**
 * swap - function
 * @stack : stack
 * @line_number : line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int count;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		freee(*stack);
		exit(EXIT_FAILURE);
	}
	count = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = count;
}

#include "monty.h"

/**
 * sub - function
 * @stack : stack
 * @line_number : line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - function
 * @stack : stack
 * @line_number : line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || ((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - function
 * @stack : stack
 * @line_number : line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || ((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                fclose(file);
                free(*stack);
                exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(file);
		freee(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

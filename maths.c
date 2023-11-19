#include "monty.h"

/**
 * sub - function
 * @stack : stack
 * @line_number : line number
 *
 * Return : void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(fd);
		freeze(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * mul - function
 * @stack : stack
 * @line_number : line number
 *
 * Return : void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(fd);
		freeze(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	tmp = *stack;
	(*stack) = (*stack)->next;
	free(tmp);
}

/**
 * mod - function
 * @stack : stack
 * @line_number : line number
 *
 * Return : void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(fd);
		freeze(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(fd);
		freeze(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);
}
/**
 * duv - function
 * @stack : stack
 * @line_number : line number
 *
 * Return : void
 */
void duv(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(fd);
		freeze(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(fd);
		freeze(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}

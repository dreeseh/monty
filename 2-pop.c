#include "monty.h"
/**
 * _pop - pops first node off stack
 * @stack: pointer to stack
 * @line_number: line number from monty file
 * Return: is void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;
	*stack = (*stack)->next;
	free(new);
}

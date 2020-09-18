#include "monty.h"
/**
 * _add - adds the first 2 nodes values
 * @stack: pointer to top of stack
 * @line_number: line number from monty file
 * Return: is null
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int result, a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;
	a = new->n;
	b = new->next->n;
	result = a + b;
	new->next->n = result;
	*stack = new->next;
	free(new);
}

#include "monty.h"
/**
 * _sub - subtracts the top element from the second
 * @stack: pointer to the top of the stack
 * @line_number: line number from monty file
 * Return: is void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int a, b, result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;
	a = new->next->n;
	b = new->n;
	result = a - b;
	new->next->n = result;
	*stack = new->next;
	free(new);
}

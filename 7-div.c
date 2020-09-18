#include "monty.h"
/**
 * _div - divides the second top element by the first
 * @stack: pointer to the top of the stack
 * @line_number: line number from the monty file
 * Return: is none
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int a, b, result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;
	if (new->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = new->next->n;
	b = new->n;
	result = a / b;
	new->next->n = result;
	*stack = new->next;
	free(new);
}

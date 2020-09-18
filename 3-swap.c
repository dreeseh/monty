#include "monty.h"
/**
 * _swap - switches the first two ints of the stack
 * @stack: pointer to the top node of the stack
 * @line_number: line number from monty file
 * Return: is void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	int node_value;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	if (new->next != NULL)
	{
		new = new->next;
	}

	node_value = new->prev->n;
	new->prev->n = new->n;
	new->n = node_value;

}

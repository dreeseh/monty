#include "monty.h"
/**
 * _swap - switches the first two ints of the stack
 * @stack: pointer to the top node of the stack
 * @line_number: line number from monty file
 * Return: is void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	(*stack)->prev = new;
	new->prev = NULL;
	(*stack)->next = new->next;

	if (new->next != NULL)
	{
		new->next = *stack;
		new->prev = *stack;
		*stack = new;
	}
}
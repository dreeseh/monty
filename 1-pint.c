#include "monty.h"
/**
 * _pint - prints the value of top node of the stack
 * @stack: pointer to head of stack
 * @line_number: line number of monty file
 * Return: is void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

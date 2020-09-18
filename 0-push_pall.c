#include "monty.h"
/**
 * _push - pushes node to stack
 * @stack: pointer to top of stack
 * @line_number: line number from monty file
 * Return: is void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *number;

	number = strtok(NULL, "\n\t\r ");
	if (number == NULL || (!isdigit(number[0]) && number[0] != '-'))
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(number);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * _pall - prints all node values
 * @stack: pointer to top op stack
 * @line_number: line number from monty file
 * Return: is void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;

	new = *stack;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

#include "monty.h"
/**
 * _free_stacks - frees stack from memory
 * @top: top of the stack
 * Return: is void
 */
void _free_stacks(stack_t *top)
{
	stack_t *new;

	while (top)
	{
		new = top;
		top = top->next;
		free(new);
	}
}

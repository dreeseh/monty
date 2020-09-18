#ifndef _MONTY_HEADER_
#define _MONTY_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_s - global variables
 * @file: the monty file to be opened
 * @line: line from getline
 * @stack: a global stack
 */
typedef struct global_s
{
	FILE *global_stream;
	char *global_line;
	stack_t *global_stack;
} global_t;

extern global_t globe;

/* mandatory tasks */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/* helper functions */
void _find_opcode(char *command, size_t number);
void _run_command(char *line, size_t number);
void _free_variables(void);
void _free_stacks(stack_t *top);

/* advanced */
void _sub(stack_t **stack, unsigned int line_numner);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_HEADER_ */

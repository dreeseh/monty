#include "monty.h"
/**
 * _run_command - runs command from monty file
 * @line: input string from monty file
 * @number: line number
 * Return: is void
 */
void _run_command(char *line, size_t number)
{
	char *command;

	command = strtok(line, "\n\t\r ");
	if (command && command[0] != '#')
	{
		_find_opcode(command, number);
	}
}

/**
 * _find_opcode - determines which opcode to use
 * @command: command from command line
 * @number: line number from monty file
 * Return: is void
 */
void _find_opcode(char *command, size_t number)
{
	int i;

	static const instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{NULL, NULL}
	};

	for (i = 0 ; ops[i].opcode ; i++)
	{
		if (strcmp(command, ops[i].opcode) == 0)
		{
			ops[i].f(&globe.global_stack, number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", (int)number, command);
	exit(EXIT_FAILURE);
}

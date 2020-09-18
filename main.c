#include "monty.h"
global_t globe = {NULL, NULL, NULL};
/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: pointer to array of arguments
 * Return: exit on success or fail
 */
int main(int argc, char **argv)
{
	size_t len, num;

	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}

	globe.global_stream = fopen(argv[1], "r");

	if (!globe.global_stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&globe.global_line, &len, globe.global_stream) != -1)
	{
		_run_command(globe.global_line, ++num);
	}

	_free_stacks(globe.global_stack);
	fclose(globe.global_stream);
	if (globe.global_line)
	{
		free(globe.global_line);
	}

	return (EXIT_SUCCESS);
}

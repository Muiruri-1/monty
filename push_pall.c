#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!data || !data->operand || !is_number(data->operand))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(data->operand);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_nod)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = valu;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *monty_file = fopen(argv[1], "r");

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, monty_file) != -1)
	{
		line_number++;
		instruction_t *data = parse_line(line);

		if (!data)
		{
			fprintf(stderr, "L%u: unknown instruction\n", line_number);
			free(line);
			fclose(monty_file);
			exit(EXIT_FAILURE);
		}
		execute_opcode(data, &stack, line_number);
		free(data->opcode);
		free(data->operand);
		free(data);
	}
	free(line);
	fclose(monty_file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}


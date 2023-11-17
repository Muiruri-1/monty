/* Filename: push.c */

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
	/* Convert the operand to an integer */
	int value = atoi(data->operand);
	/* Create a new stack node */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	/* Update the previous top of the stack, if it exists */
	if (*stack)
		(*stack)->prev = new_node;
	/* Set the new node as the top of the stack */
	*stack = new_node;
}


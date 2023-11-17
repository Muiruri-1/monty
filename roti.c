/* Filename: rotl.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Avoid unused parameter warning */

	if (stack && *stack && (*stack)->next)
	{
		stack_t *last = *stack;

		while (last->next)
			last = last->next;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}


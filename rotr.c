/* Filename: rotr.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Avoid unused parameter warning */

	if (stack && *stack && (*stack)->next)
	{
		stack_t *last = *stack;

		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		last->prev = NULL;
		*stack = last;
	}
}


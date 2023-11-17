/* Filename: sub.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);  /* Remove the top element */
}


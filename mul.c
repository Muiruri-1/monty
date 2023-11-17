/* Filename: mul.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mul - Multiplies the second top element with the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);  /* Remove the top element */
}


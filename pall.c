/* Filename: pall.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	/* Print all values on the stack */
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


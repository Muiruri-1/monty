/* Filename: pstr.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* Avoid unused parameter warning */

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}


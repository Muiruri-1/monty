/* Filename: nop.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * nop - Doesn't do anything.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Avoid unused parameter warning */
	(void)line_number; /* Avoid unused parameter warning */
	/* This opcode does nothing */
}

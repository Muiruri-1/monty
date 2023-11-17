/* Filename: stack_queue.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Avoid unused parameter warning */
	/* This opcode is already in stack mode, do nothing */
	(void)stack;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Avoid unused parameter warning */

	if (stack && *stack && (*stack)->next)
	{
		stack_t *front = *stack;

		while (front->next)
			front = front->next;
		(*stack)->prev = front;
		front->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}


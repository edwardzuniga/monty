#include "monty.h"

/**
 * nop_function - implement the nop function
 * @stack: stack
 * @line_num: line number
 */
void nop_function(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
 * swap_function - swaps the top two elements of the stack
 * @stack: stack
 * @line_num: line num
 */

void swap_function(stack_t **stack, unsigned int line_num)
{
	stack_t *top = NULL;
	stack_t *second = NULL;

	top = *stack;
	if (top == NULL || top->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	second = (*stack)->next;

	top->prev = second;
	second->prev = NULL;
	top->next = second->next;
	second->next = top;

	*stack = second;

}

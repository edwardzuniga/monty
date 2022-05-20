#include "monty.h"

/**
 * add_op - adds the values of the top two nodes
 * @stack: stack
 * @line_num: line number
 */

void add_op(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int sum = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->next->n;
	temp->next->n = sum;

	pop_function(stack, line_num);
}

/**
 * sub_op - subtracts the top element from the second top element
 * @stack: stack
 * @line_num: line number
 */

void sub_op(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int diff = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	diff = temp->next->n - temp->n;
	temp->next->n = diff;

	pop_function(stack, line_num);
}

/**
 * mul_op - multiplies the second top element of the stack with the top
 * @stack: stack
 * @line_num: line number
 */

void mul_op(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int factor = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	factor = temp->next->n * temp->n;
	temp->next->n = factor;

	pop_function(stack, line_num);
}

/**
 * div_op - divides the second top element of the stack by the top element
 * @stack: stack
 * @line_num: line number
 */

void div_op(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int quotient = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	quotient = temp->next->n / temp->n;
	temp->next->n = quotient;

	pop_function(stack, line_num);
}

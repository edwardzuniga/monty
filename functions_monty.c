#include "monty.h"

/**
 * push_function - pushes an element to the stack
 * @stack: stack
 * @line_num: line number
 */

void push_function(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;

	(void) line_num;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/**
 * pall_function - prints all the values on the stack, starting from the top
 * @stack: stack
 * @line_num: line number
 */

void pall_function(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	(void) line_num;
	temp = *stack;
	if ((*stack) == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_function - prints the value at the top of the stack
 * @stack: stack
 * @line_num: line number
 */
void pint_function(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d\n", temp->n);
}

/**
 * pop_function - pop top node in stack
 * @stack: stack
 * @line_num: line number
 */
void pop_function(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * get_function - matches opcode from input to existing opcode in struct
 * @op: character to check
 * @stack: stack
 * @line_num: line number
 *
 * Return: the pointer to the appropriate function or NULL if nothing matches
 */

void get_function(char *op, stack_t **stack, unsigned int line_num)
{
	instruction_t find_op[] = {
		{"push", push_function},
		{"pall", pall_function},
		{"pint", pint_function},
		{"pop", pop_function},
		{"nop", nop_function},
		{"add", add_op},
		{"swap", swap_function},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{NULL, NULL}
	};
	int index = 0;

	while (find_op[index].opcode != NULL)
	{
		if (strcmp(find_op[index].opcode, op) == 0)
		{
			find_op[index].f(stack, line_num);
			return;
		}
		index++;
	}
	printf("L%d: unknown instruction %s\n", line_num, op);
	exit(EXIT_FAILURE);
}

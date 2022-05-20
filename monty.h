#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
extern int global_var;
int global_var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int is_num(char *str);
char *get_token(char *line, unsigned int line_num);
void nop_function(stack_t **stack, unsigned int line_num);
void swap_function(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *head);
int main(int argc, char *argv[]);
void add_op(stack_t **stack, unsigned int line_num);
void sub_op(stack_t **stack, unsigned int line_num);
void mul_op(stack_t **stack, unsigned int line_num);
void div_op(stack_t **stack, unsigned int line_num);
void push_function(stack_t **stack, unsigned int line_num);
void pall_function(stack_t **stack, unsigned int line_num);
void pint_function(stack_t **stack, unsigned int line_num);
void pop_function(stack_t **stack, unsigned int line_num);
void get_function(char *op, stack_t **stack, unsigned int line_num);


#endif
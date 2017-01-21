#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* initialize global array */
extern int glob[];

/* push function */
void _push(stack_t **head, unsigned int line_number);
/* print all function */
void _pall(stack_t **head, unsigned int line_number);
/* print first int on stack*/
void _pint(stack_t **head, unsigned int line_number);
/* pop off the stack */
void _pop(stack_t **head, unsigned int line_number);
/* swap top two on stack*/
void _swap(stack_t **head, unsigned int line_number);


/* add top two on stack*/
void _add(stack_t **head, unsigned int line_number);
/* a function that does nothing */
void _nop(stack_t **head, unsigned int line_number);
/* sub top two on stack*/
void _sub(stack_t **head, unsigned int line_number);
/* div top two on stack*/
void _div(stack_t **head, unsigned int line_number);
/* mul top two on stack*/
void _mul(stack_t **head, unsigned int line_number);


/* mod top two on stack*/
void _mod(stack_t **head, unsigned int line_number);
/* print top of stack as char */
void _pchar(stack_t **head, unsigned int line_number);
/* print stack as a string */
void _pstr(stack_t **head, unsigned int line_number);
/* rotate top element to be last element */
void _rotl(stack_t **head, unsigned int line_number);

/* helper functions*/
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
stack_t *find_end(stack_t **head);
char *get_cmd(char *line, unsigned int line_num);
#endif

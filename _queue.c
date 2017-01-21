#include "monty.h"

/**
 * _queue - set status to be queue
 * @head: unneeded value
 * @line_number: unneeded value
 * Return: nothing
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;

	glob[1] = 1;
}

/**
 * _stack - set status to be stack
 * @head: unneeded value
 * @line_number: unneeded value
 * Return: nothing
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;

	glob[1] = 0;
}

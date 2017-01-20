#include "monty.h"

/**
 * _push - function that will push integer n onto stack
 * @start: start of stack
 * @n: value to store on stack
 * Return: last element in stack
 */
struct_t *_push(struct_t **head, unsigned int line_number)
{
	struct_t *temp;

	temp = add_node_end(head, n);
	return (temp);
}

/**
 * _pall - function that wil print everything out on stack
 * @end: end of stack
 * Return: number of elements printed
 */
size_t _pall(struct_t **head, unsigned int line_number)
{
	struct_t *temp;
	size_t i;

	temp = find_end(head);
	for (i = 0; temp != NULL; temp = temp->prev, i++)
	{
		printf("%d\n", temp->n);
	}
	return (i);
}

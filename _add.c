#include "monty.h"
nn
/**
 * _add - add the top two number of the stack together
 * @head: beginning of the stack
 * @line_number: line number of command in text
 * Return: nothing
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n + temp->n;
	_pop(head, line_number);
	_pop(head, line_number);
	add_node_end(head, i);
}

/**
 * _nop - a function that does nothing
 * @head: useless input
 * @line_number: useless input
 * Return: nothing
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	return;
}

/**
 * _sub - subtract the top value from the second to top value
 * @head: beginning of the stack
 * @line_number: line number of command in stack
 * Return: nothing
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n - temp->n;
	_pop(head, line_number);
	_pop(head, line_number);
	add_node_end(head, i);
}

/**
 * _div - divide the second value by the top value
 * @head: beginning of the stack
 * @line_number: line number of command in stack
 * Return: nothing
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n / temp->n;
	_pop(head, line_number);
	_pop(head, line_number);
	add_node_end(head, i);
}

/**
 * _mul - multiply the top two values together
 * @head: beginning of the satck
 * @line_number: line number of command in stack
 * Return: nothing
 */
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n * temp->n;
	_pop(head, line_number);
	_pop(head, line_number);
	add_node_end(head, i);
}

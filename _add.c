#include "monty.h"

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
	glob[0] = i;
	_pop(head, line_number);
	_pop(head, line_number);
	_push(head, line_number);
}

void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	return;
}

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
	glob[0] = i;
	_pop(head, line_number);
	_pop(head, line_number);
	_push(head, line_number);
}

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
	glob[0] = i;
	_pop(head, line_number);
	_pop(head, line_number);
	_push(head, line_number);
}

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
	glob[0] = i;
	_pop(head, line_number);
	_pop(head, line_number);
	_push(head, line_number);
}
